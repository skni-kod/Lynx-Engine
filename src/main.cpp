#pragma comment(linker, "/SUBSYSTEM:WINDOWS")
#include <iostream>
#include <windows.h>


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    MSG msg;
    HWND hwnd;
    WNDCLASSW wc;

    wc.style            = CS_HREDRAW | CS_VREDRAW;          // Okienko jest responsywnie przerysowywane gdy zmieniany jest jego rozmiar
    wc.cbClsExtra       = 0;                                // Zmienne do subclassingu
    wc.cbWndExtra       = 0;                                // Zmienne do subclassingu
    wc.lpszClassName    = L"Window";                        // Nazwa klasy typu okienka (L - wide string)
    wc.hInstance        = hInstance;                        // Ustawianie instancji okienka
    wc.hbrBackground    = GetSysColorBrush(COLOR_3DFACE);   // Ustawianie logicznego pędzla tła
    wc.lpszMenuName     = NULL;                             // Nie robimy menu (narazie)
    wc.lpfnWndProc      = WndProc;                          // Ustawienie procedury okienka
    wc.hCursor          = LoadCursor(NULL, IDC_ARROW);      // Ustawienie kursora w okienku
    wc.hIcon            = LoadIcon(NULL, IDI_APPLICATION);  // Ustawienie ikonki okienka

    RegisterClassW(&wc);                                    // Rejestracja klasy okienka w systemie
    hwnd = CreateWindowW(wc.lpszClassName, L"Lynx Engine Window",   // Tworzenie okienka z wszystkimi powyższymi danymi
                        WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
                        CW_USEDEFAULT, CW_USEDEFAULT, 
                        CW_USEDEFAULT, CW_USEDEFAULT, 
                        NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);                             // Pokaznie okienka na ekranie
    UpdateWindow(hwnd);                                     // Aktualizowanie okienka

    while(GetMessage(&msg, NULL, 0, 0))                     // Handler wiadomości dla windowsa
    {
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;                                // Zwracanie exit code
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)                                             // Switch z reakcjami na poszczególne wiadomości zwracane przez okienko
    {
        case WM_DESTROY:
            PostQuitMessage(0);                             // Wysłanie wiadomości WM_QUIT do kolejki wiadomości
            break;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);       // Standardowe przetwarzanie wiadomości (wiadomości nieobdługiwane w powyższym switchu trafiają do niego)
}


