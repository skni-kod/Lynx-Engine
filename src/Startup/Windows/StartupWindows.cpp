#include <cstdint>
#include <cstdio>
#include <io.h>
#include <fcntl.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

extern "C"
{
    HINSTANCE hInstance = NULL;
}

extern int32_t GenericMain();

int APIENTRY WinMain(HINSTANCE hInInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    int32_t ErrorLevel = 0;

    hInstance = hInInstance;

#ifdef DEBUG
    AllocConsole();
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long)handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;

    FILE* ptrConout, * ptrConin;
    freopen_s(&ptrConout, "CONOUT$", "w", stdout);
    freopen_s(&ptrConin, "CONIN$", "r", stdin);
#endif

    printf("Hello from Windows Main in LYNX ENGINE!\n");

    ErrorLevel = GenericMain();
    return ErrorLevel;
}
