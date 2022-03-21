#include "Platform/Windows/WindowsGLContext.h"
#include "Platform/Windows/WindowsGLExtensions.h"
#include <iostream>

PFNWGLCREATECONTEXTATTRIBSARBPROC	wglCreateContextAttribsARB;
PFNWGLCHOOSEPIXELFORMATARBPROC		wglChoosePixelFormatARB;
PFNGLGENBUFFERSPROC					glGenBuffers;
PFNGLBINDBUFFERPROC					glBindBuffer;
PFNGLBUFFERDATAPROC					glBufferData;
PFNGLCREATESHADERPROC				glCreateShader;
PFNGLSHADERSOURCEPROC				glShaderSource;
PFNGLCOMPILESHADERPROC				glCompileShader;
PFNGLGETSHADERINFOLOGPROC			glGetShaderInfoLog;
PFNGLGETSHADERIVPROC				glGetShaderiv;
PFNGLATTACHSHADERPROC				glAttachShader;
PFNGLLINKPROGRAMPROC				glLinkProgram;
PFNGLGETPROGRAMINFOLOGPROC			glGetProgramInfoLog;
PFNGLGETPROGRAMIVPROC				glGetProgramiv;
PFNGLUSEPROGRAMPROC					glUseProgram;
PFNGLBINDVERTEXARRAYPROC			glBindVertexArray;
PFNGLCREATEPROGRAMPROC				glCreateProgram;
PFNGLDELETEBUFFERSPROC				glDeleteBuffers;
PFNGLDELETEPROGRAMPROC				glDeleteProgram;
PFNGLDELETESHADERPROC				glDeleteShader;
PFNGLDELETEVERTEXARRAYSPROC			glDeleteVertexArrays;
PFNGLDETACHSHADERPROC				glDetachShader;
PFNGLENABLEVERTEXATTRIBARRAYPROC	glEnableVertexAttribArray;
PFNGLGENVERTEXARRAYSPROC			glGenVertexArrays;
PFNGLGETATTRIBLOCATIONPROC			glGetAttribLocation;
PFNGLVERTEXATTRIBPOINTERPROC		glVertexAttribPointer;
PFNGLBINDATTRIBLOCATIONPROC			glBindAttribLocation;
PFNGLGETUNIFORMLOCATIONPROC			glGetUniformLocation;
PFNGLUNIFORMMATRIX4FVPROC			glUniformMatrix4fv;
PFNGLACTIVETEXTUREPROC				glActiveTexture;
PFNGLUNIFORM1IPROC					glUniform1i;
PFNGLGENERATEMIPMAPPROC				glGenerateMipmap;
PFNGLDISABLEVERTEXATTRIBARRAYPROC	glDisableVertexAttribArray;
PFNGLUNIFORM3FVPROC					glUniform3fv;
PFNGLUNIFORM4FVPROC					glUniform4fv;

static bool LoadGLExtensions(HWND hwnd)
{
	HDC m_DC;
	PIXELFORMATDESCRIPTOR pfd;
	HGLRC glContext;

	m_DC = GetDC(hwnd);
	if (!m_DC) return false;

	//TODO check errors
	SetPixelFormat(m_DC, 1, &pfd);
	
	glContext = wglCreateContext(m_DC);
	if (!glContext) return false;

	wglMakeCurrent(m_DC, glContext);

	//TODO check if function was loaded correctly
	wglCreateContextAttribsARB	=	(PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
	if (!wglCreateContextAttribsARB)
	{
		printf("Missing wglCreateContextAttribsARB\n");
	}

	wglChoosePixelFormatARB		=	(PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
	if (!wglChoosePixelFormatARB)
	{
		printf("Missing wglChoosePixelFormatARB\n");
	}

	glGenBuffers				=	(PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
	if (!glGenBuffers)
	{
		printf("Missing glGenBuffers\n");
	}

	glBindBuffer				=	(PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	if (!glBindBuffer)
	{
		printf("Missing glBindBuffer\n");
	}

	glBufferData				=	(PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
	if (!glBufferData)
	{
		printf("Missing glBufferData\n");
	}
	
	glCreateShader				=	(PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
	if (!glCreateShader)
	{
		printf("Missing glCreateShader\n");
	}

	glShaderSource				=	(PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	if (!glShaderSource)
	{
		printf("Missing glShaderSource\n");
	}

	glCompileShader				=	(PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
	if (!glCompileShader)
	{
		printf("Missing glCompileShader\n");
	}

	glGetShaderInfoLog			=	(PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
	if (!glGetShaderInfoLog)
	{
		printf("Missing glGetShaderInfoLog\n");
	}

	glGetShaderiv				=	(PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
	if (!glGetShaderiv)
	{
		printf("Missing glGetShaderiv\n");
	}

	glAttachShader				=	(PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
	if (!glAttachShader)
	{
		printf("Missing glAttachShader\n");
	}
	
	glBindVertexArray			=	(PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
	if (!glBindVertexArray)
	{
		printf("Missing glBindVertexArray\n");
	}

	glCreateProgram				=	(PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	if (!glCreateProgram)
	{
		printf("Missing glCreateProgram\n");
	}

	glDeleteBuffers				=	(PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
	if (!glDeleteBuffers)
	{
		printf("Missing glDeleteBuffers\n");
	}

	glDeleteProgram				=	(PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
	if (!glDeleteProgram)
	{
		printf("Missing glDeleteProgram\n");
	}

	glDeleteShader				=	(PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
	if (!glDeleteShader)
	{
		printf("Missing glDeleteShader\n");
	}

	glDeleteVertexArrays		=	(PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
	if (!glDeleteVertexArrays)
	{
		printf("Missing glDeleteVertexArrays\n");
	}

	glDetachShader				=	(PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
	if (!glDetachShader)
	{
		printf("Missing glDetachShader\n");
	}

	glEnableVertexAttribArray	=	(PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
	if (!glEnableVertexAttribArray)
	{
		printf("Missing glEnableVertexAttribArray\n");
	}

	glGenVertexArrays			=	(PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
	if (!glGenVertexArrays)
	{
		printf("Missing glGenVertexArrays\n");
	}

	glGetAttribLocation			=	(PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
	if (!glGetAttribLocation)
	{
		printf("Missing glGetAttribLocation\n");
	}

	glGetProgramInfoLog			=	(PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
	if (!glGetProgramInfoLog)
	{
		printf("Missing glGetProgramInfoLog\n");
	}

	glGetProgramiv				=	(PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
	if (!glGetProgramiv)
	{
		printf("Missing glGetProgramiv\n");
	}

	glGetShaderInfoLog			=	(PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
	if (!glGetShaderInfoLog)
	{
		printf("Missing glGetShaderInfoLog\n");
	}

	glGetShaderiv				=	(PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
	if (!glGetShaderiv)
	{
		printf("Missing glGetShaderiv\n");
	}

	glLinkProgram				=	(PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
	if (!glLinkProgram)
	{
		printf("Missing glLinkProgram\n");
	}

	glShaderSource				=	(PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	if (!glShaderSource)
	{
		printf("Missing glShaderSource\n");
	}

	glUseProgram				=	(PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
	if (!glUseProgram)
	{
		printf("Missing glUseProgram\n");
	}

	glVertexAttribPointer		=	(PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
	if (!glVertexAttribPointer)
	{
		printf("Missing glVertexAttribPointer\n");
	}

	glBindAttribLocation		=	(PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
	if (!glBindAttribLocation)
	{
		printf("Missing glBindAttribLocation\n");
	}

	glGetUniformLocation		=	(PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
	if (!glGetUniformLocation)
	{
		printf("Missing glGetUniformLocation\n");
	}

	glUniformMatrix4fv			=	(PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
	if (!glUniformMatrix4fv)
	{
		printf("Missing glUniformMatrix4fv\n");
	}

	glActiveTexture				=	(PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
	if (!glActiveTexture)
	{
		printf("Missing glActiveTexture\n");
	}

	glUniform1i					=	(PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
	if (!glUniform1i)
	{
		printf("Missing glUniform1i\n");
	}

	glGenerateMipmap			=	(PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
	if (!glGenerateMipmap)
	{
		printf("Missing glGenerateMipmap\n");
	}

	glDisableVertexAttribArray	=	(PFNGLDISABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glDisableVertexAttribArray");
	if (!glDisableVertexAttribArray)
	{
		printf("Missing glDisableVertexAttribArray\n");
	}

	glUniform3fv				=	(PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
	if (!glUniform3fv)
	{
		printf("Missing glUniform3fv\n");
	}

	glUniform4fv				=	(PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
	if (!glUniform4fv)
	{
		printf("Missing glUniform4fv\n");
	}

	//Clean temp context
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(glContext);
	glContext = NULL;

	ReleaseDC(hwnd, m_DC);
	m_DC = NULL;

    return true;
}

bool InitWindowsGLExtensions(HINSTANCE& hInstance)
{
    HWND winHandle;
    winHandle = CreateWindowW(L"LynxWindow", L"Lynx Engine Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, NULL, NULL, hInstance, NULL);
    ShowWindow(winHandle, SW_HIDE);
    if(!LoadGLExtensions(winHandle));
        return false;
    DestroyWindow(winHandle);
    return true;
}

HGLRC InitWindowsGLContext(HWND hwnd, HINSTANCE& hInstance)
{
	//handle to the device context
    HDC dc;
    HGLRC glContext;

    int contextAttribList[5];
	int pfdAttribList[19];

	PIXELFORMATDESCRIPTOR pfd;
	unsigned int formatCount;
	int pixelFormat[1];

	dc = GetDC(hwnd);

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

	wglChoosePixelFormatARB(dc, pfdAttribList, NULL, 1, pixelFormat, &formatCount);
	SetPixelFormat(dc, pixelFormat[0], &pfd);

	//Create context with given GL version
    //HERE WE DO SET WHICH VERSION OF OPENGL WE WANT TO SUPPORT
	contextAttribList[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
	contextAttribList[1] = 3;
	contextAttribList[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
	contextAttribList[3] = 3;
	contextAttribList[4] = NULL;

	glContext = wglCreateContextAttribsARB(dc, NULL, contextAttribList);
	wglMakeCurrent(dc, glContext);

    return glContext;
}