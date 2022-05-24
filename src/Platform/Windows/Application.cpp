#include "Platform/Generic/Application.h"
#include "Platform/Generic/Window.h"
#include "GL/GL.hpp"

#include <cstdio>
#include <vector>
#include <fstream>
#include <sstream>

extern "C" HINSTANCE hInstance;

bool Application::running = false;
Window* Application::mainWindow = nullptr;


static HDC deviceContext;
static PIXELFORMATDESCRIPTOR pixelFormatDesc;
static HGLRC glContext;


//This is going to be removed from here, currently only for testing purposes
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

//GL buffers, etc.
unsigned int VAO, VBO;
unsigned int vs, fs, prog;

//END OF REMOVE

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    LRESULT Result = 0;
    // Message handling
    static PAINTSTRUCT ps;
    switch (uMsg)
    {
    case WM_DESTROY:
        printf("WM_DESTROY\n");
        //wglDeleteContext(GLContext);
        //Figure out better way to tell application to quit, currently it is tied to main window, which under windows is kinda bad, due to creating dummy window for GL
        //This means only this if prevents engine from closing after removing dummy window.
        if(Application::mainWindow != nullptr)
            PostQuitMessage(0);
        
        break;

    case WM_CLOSE:
        printf("WM_CLOSE\n");
        DestroyWindow(hwnd);    // Closing Window
        //PostQuitMessage(0);
        //exit(0);
        break;
    case WM_PAINT:
        BeginPaint(hwnd, &ps);
        EndPaint(hwnd, &ps);
        break;
    case WM_SIZE:
        //glViewport(0, 0, LOWORD(lParam), HIWORD(lParam)); //Setup viewport to new size.
        //ChangeProjection(LOWORD(lParam), HIWORD(lParam));
        PostMessage(hwnd, WM_PAINT, 0, 0);
        break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window* Application::MakeWindow(int32_t x, int32_t y, int32_t w, int32_t h, wchar_t* name)
{
	Window* Win = new Window();
	Win->windowData.hwnd = CreateWindowEx(0, WindowData::AppWindowClass, name, WS_OVERLAPPEDWINDOW, x, y, w, h, NULL, NULL, hInstance, NULL);
	return (Window*)Win;
}

void Application::UpdatePlatform()
{

}

void Application::MainLoop()
{
    MSG msg;
    while (Application::running)
    {
        if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        
        if(msg.message == WM_QUIT)
        {
            Application::running = false;
        }
        
        Application::UpdatePlatform();
        //TESTING
        Application::DrawGLTriangle();
    }
}

void Application::Init()
{
    WNDCLASS WindowClass = {};

    WindowClass.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
    WindowClass.lpfnWndProc = WindowProc;
    WindowClass.hInstance = hInstance;
    WindowClass.lpszClassName = L"LynxWindow";

    //Register Window Class
    RegisterClass(&WindowClass);

    //Everything went fine - set running flag to true.
    Application::running = true;
}

//TODO: Add error checking!!!
void Application::InitGL()
{
    //Not even sure why they did this that way.
    HWND dummyWindow = CreateWindowEx(0, WindowData::AppWindowClass, L"Dummy", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    ShowWindow(dummyWindow, SW_HIDE);
    HDC m_DC;
    PIXELFORMATDESCRIPTOR pfdTemp = {};
    HGLRC glContextTemp;

    m_DC = GetDC(dummyWindow);
    //if (!m_DC) return false;

    //TODO check errors
    SetPixelFormat(m_DC, 1, &pfdTemp);

    glContextTemp = wglCreateContext(m_DC);
    //if (!glContext) return false;

    wglMakeCurrent(m_DC, glContextTemp);

    loadGL();

    //Clean temp things, since we now know where all extensions functions are and we can create proper window.
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(glContextTemp);
    glContextTemp = NULL;

    ReleaseDC(dummyWindow, m_DC);
    m_DC = NULL;

    DestroyWindow(dummyWindow);
    dummyWindow = NULL;
}

void Application::CreateGLDevice()
{
    int contextAttribList[5] = {};
    int pfdAttribList[19] = {};

    unsigned int formatCount;
    int pixelFormat[1];

    deviceContext = GetDC(Application::mainWindow->windowData.hwnd);

    //Add PFD
    pfdAttribList[0] = WGL_SUPPORT_OPENGL_ARB;
    pfdAttribList[1] = TRUE;

    pfdAttribList[2] = WGL_DRAW_TO_WINDOW_ARB;
    pfdAttribList[3] = TRUE;

    pfdAttribList[4] = WGL_ACCELERATION_ARB;
    pfdAttribList[5] = WGL_FULL_ACCELERATION_ARB;

    pfdAttribList[6] = WGL_COLOR_BITS_ARB;
    pfdAttribList[7] = 24;

    pfdAttribList[8] = WGL_DEPTH_BITS_ARB;
    pfdAttribList[9] = 24;

    pfdAttribList[10] = WGL_DOUBLE_BUFFER_ARB;
    pfdAttribList[11] = TRUE;

    pfdAttribList[12] = WGL_SWAP_METHOD_ARB;
    pfdAttribList[13] = WGL_SWAP_EXCHANGE_ARB;

    pfdAttribList[14] = WGL_PIXEL_TYPE_ARB;
    pfdAttribList[15] = WGL_TYPE_RGBA_ARB;

    pfdAttribList[16] = WGL_STENCIL_BITS_ARB;
    pfdAttribList[17] = 8;

    pfdAttribList[18] = NULL;

    wglChoosePixelFormatARB(deviceContext, pfdAttribList, NULL, 1, pixelFormat, &formatCount);
    SetPixelFormat(deviceContext, pixelFormat[0], &pixelFormatDesc);

    //Create context with given GL version
    contextAttribList[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
    contextAttribList[1] = 3;
    contextAttribList[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
    contextAttribList[3] = 3;
    contextAttribList[4] = NULL;

    glContext = wglCreateContextAttribsARB(deviceContext, NULL, contextAttribList);
    wglMakeCurrent(deviceContext, glContext);

    //THIS IS SHARED CODE

    //THIS IS JUST FOR TESTING, REMOVE LATER
    //Make something to draw:
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
}

void Application::DrawGLTriangle()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Insert drawing code here

    glUseProgram(prog);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    //Swap buffer, thus ending frame
    SwapBuffers(deviceContext);
}