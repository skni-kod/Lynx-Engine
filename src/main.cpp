#pragma comment(linker, "/SUBSYSTEM:WINDOWS")
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <io.h>
#include <fcntl.h>

#include <fstream>
#include <sstream>
#include <vector>

#include "Platform/Windows/WindowsGLContext.h"
#include "Platform/Windows/WindowsGLExtensions.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void Init();
void Draw();

//temporary, for testing
unsigned int VAO, VBO;
unsigned int vs, fs, prog;

//coppied from other project, we'll create our own definitions later
struct vertex
{
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float a;

    vertex(float x, float y, float z, float r, float g, float b, float a) :
        x(x), y(y), z(z), r(r), g(g), b(b), a(a)
    {

    }

    vertex(float x, float y, float z) :
        x(x), y(y), z(z), r(0.5f), g(0.4f), b(0.9f), a(255)
    {

    }
};

std::vector<vertex> vertices;
std::vector<int> indices;

HDC dc;
HGLRC glContext;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    MSG msg;
    HWND hwnd;
    WNDCLASSW wc;
    //we'll figure out better way
    bool running = true;

    //allow usage of console even in WINDOWS subsystem and redirect stdin and stdout to that console
    AllocConsole();
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    int hCrt = _open_osfhandle((uint64_t)handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((uint64_t)handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;

    FILE* ptrConout, *ptrConin;
    freopen_s(&ptrConout, "CONOUT$", "w", stdout);
    freopen_s(&ptrConin, "CONIN$", "r", stdin);

    printf("Now we have working console in Windows subsystem!\n");

    wc.style            = CS_HREDRAW | CS_VREDRAW;          // Okienko jest responsywnie przerysowywane gdy zmieniany jest jego rozmiar
    wc.cbClsExtra       = 0;                                // Zmienne do subclassingu
    wc.cbWndExtra       = 0;                                // Zmienne do subclassingu
    wc.lpszClassName    = L"LynxWindow";                        // Nazwa klasy typu okienka (L - wide string)
    wc.hInstance        = hInstance;                        // Ustawianie instancji okienka
    wc.hbrBackground    = GetSysColorBrush(COLOR_3DFACE);   // Ustawianie logicznego pędzla tła
    wc.lpszMenuName     = NULL;                             // Nie robimy menu (narazie)
    wc.lpfnWndProc      = WndProc;                          // Ustawienie procedury okienka
    wc.hCursor          = LoadCursor(NULL, IDC_ARROW);      // Ustawienie kursora w okienku
    wc.hIcon            = LoadIcon(NULL, IDI_APPLICATION);  // Ustawienie ikonki okienka

    RegisterClassW(&wc);                                    // Rejestracja klasy okienka w systemie
    //Load GL Extensions
    InitWindowsGLExtensions(hInstance);
    hwnd = CreateWindowW(wc.lpszClassName, L"Lynx Engine Window",   // Tworzenie okienka z wszystkimi powyższymi danymi
                        WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
                        CW_USEDEFAULT, CW_USEDEFAULT, 
                        1280, 720, 
                        NULL, NULL, hInstance, NULL);

    //create GLContext for newly created window.
    glContext = InitWindowsGLContext(hwnd, hInstance);      

    dc = GetDC(hwnd);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SwapBuffers(dc);
    
    ShowWindow(hwnd, nCmdShow);                             // Pokaznie okienka na ekranie
    UpdateWindow(hwnd);                                     // Aktualizowanie okienka

    Init();
    while (running)
    {
        while (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (msg.message == WM_QUIT)
        {
            running = false;
        }
        else
        {
            //Kinda main loop here
            Draw();
        }
    }
    return (int) msg.wParam;                                // Zwracanie exit code
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)                                             // Switch z reakcjami na poszczególne wiadomości zwracane przez okienko
    {
        case WM_DESTROY:
            wglDeleteContext(glContext);
            PostQuitMessage(0);                             // Wysłanie wiadomości WM_QUIT do kolejki wiadomości
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);    // Closing Window
            exit(0);
            break;
        case WM_SIZE:
            glViewport(0, 0, LOWORD(lParam), HIWORD(lParam)); //Setup viewport to new size.
            PostMessage(hwnd, WM_PAINT, 0, 0);
            break;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);       // Standardowe przetwarzanie wiadomości (wiadomości nieobdługiwane w powyższym switchu trafiają do niego)
}


void Init()
{
    std::ifstream vertSource;
    std::ifstream fragSource;
    std::stringstream vertexStream, fragmentStream;
    std::string vertCode, fragCode;

    vertSource.open("assets/shader/standard.vs");
    vertexStream << vertSource.rdbuf();
    vertCode = vertexStream.str();

    fragSource.open("assets/shader/standard.fs");
    fragmentStream << fragSource.rdbuf();
    fragCode = fragmentStream.str();

    const char* vertCodePtr = vertCode.c_str();
    const char* fragCodePtr = fragCode.c_str();

    //Create vertex shader object
    vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertCodePtr, NULL);
    glCompileShader(vs);

    //Create fragment shader object
    fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragCodePtr, NULL);
    glCompileShader(fs);

    //Attach compiled shader code and link it with shader program
    prog = glCreateProgram();
    glAttachShader(prog, vs);
    glAttachShader(prog, fs);
    glLinkProgram(prog);
    
    //Select newly linked shader program as currently used one
    glUseProgram(prog);

    //Delete shader objects, since we already linked them in shader program object.
    glDeleteShader(vs);
    glDeleteShader(fs);

    vertices.push_back(vertex(-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f));
    vertices.push_back(vertex(0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f));
    vertices.push_back(vertex(0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f));

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(0));
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(3 * sizeof(float)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Draw()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(prog);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    SwapBuffers(dc);
}

