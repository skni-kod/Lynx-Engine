#ifndef WINDOWSGLEXTENSIONS_H
#define WINDOWSGLEXTENSIONS_H

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <gl/GL.h>

typedef HGLRC	(WINAPI*	PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int* attribList);
typedef BOOL	(WINAPI*	PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
typedef void	(APIENTRY*	PFNGLGENBUFFERSPROC) (GLsizei n, GLuint* buffers);
typedef void	(APIENTRY*	PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void	(APIENTRY*	PFNGLBUFFERDATAPROC) (GLenum target, ptrdiff_t size, const GLvoid* data, GLenum usage);
typedef GLuint	(APIENTRY*	PFNGLCREATESHADERPROC) (GLenum type);
typedef void	(APIENTRY*	PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const char** string, const GLint* length);
typedef void	(APIENTRY*	PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef void	(APIENTRY*	PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei* length, char* infoLog);
typedef void	(APIENTRY*	PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint* params);
typedef void	(APIENTRY*	PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void	(APIENTRY*	PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void	(APIENTRY*	PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei* length, char* infoLog);
typedef void	(APIENTRY*	PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint* params);
typedef void	(APIENTRY*	PFNGLUSEPROGRAMPROC) (GLuint program);
typedef BOOL	(WINAPI*	PFNWGLSWAPINTERVALEXTPROC) (int interval);
typedef void	(APIENTRY*	PFNGLBINDVERTEXARRAYPROC) (GLuint array);
typedef GLuint	(APIENTRY*	PFNGLCREATEPROGRAMPROC) (void);
typedef void	(APIENTRY*	PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void	(APIENTRY*	PFNGLDELETESHADERPROC) (GLuint shader);
typedef void	(APIENTRY*	PFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint* arrays);
typedef void	(APIENTRY*	PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
typedef void	(APIENTRY*	PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void	(APIENTRY*	PFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint* arrays);
typedef GLint	(APIENTRY*	PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const char* name);
typedef void	(APIENTRY*	PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
typedef void	(APIENTRY*	PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const char* name);
typedef GLint	(APIENTRY*	PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const char* name);
typedef void	(APIENTRY*	PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void	(APIENTRY*	PFNGLACTIVETEXTUREPROC) (GLenum texture);
typedef void	(APIENTRY*	PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void	(APIENTRY*	PFNGLGENERATEMIPMAPPROC) (GLenum target);
typedef void	(APIENTRY*	PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void	(APIENTRY*	PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void	(APIENTRY*	PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void	(APIENTRY*	PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint* buffers);

//functions some of these should be "redefined to hide platform specific naming" 
extern PFNWGLCREATECONTEXTATTRIBSARBPROC	wglCreateContextAttribsARB;
extern PFNWGLCHOOSEPIXELFORMATARBPROC		wglChoosePixelFormatARB;
extern PFNGLGENBUFFERSPROC					glGenBuffers;
extern PFNGLBINDBUFFERPROC					glBindBuffer;
extern PFNGLBUFFERDATAPROC					glBufferData;
extern PFNGLCREATESHADERPROC				glCreateShader;
extern PFNGLSHADERSOURCEPROC				glShaderSource;
extern PFNGLCOMPILESHADERPROC				glCompileShader;
extern PFNGLGETSHADERINFOLOGPROC			glGetShaderInfoLog;
extern PFNGLGETSHADERIVPROC				glGetShaderiv;
extern PFNGLATTACHSHADERPROC				glAttachShader;
extern PFNGLLINKPROGRAMPROC				glLinkProgram;
extern PFNGLGETPROGRAMINFOLOGPROC			glGetProgramInfoLog;
extern PFNGLGETPROGRAMIVPROC				glGetProgramiv;
extern PFNGLUSEPROGRAMPROC					glUseProgram;
extern PFNGLBINDVERTEXARRAYPROC			glBindVertexArray;
extern PFNGLCREATEPROGRAMPROC				glCreateProgram;
extern PFNGLDELETEBUFFERSPROC				glDeleteBuffers;
extern PFNGLDELETEPROGRAMPROC				glDeleteProgram;
extern PFNGLDELETESHADERPROC				glDeleteShader;
extern PFNGLDELETEVERTEXARRAYSPROC			glDeleteVertexArrays;
extern PFNGLDETACHSHADERPROC				glDetachShader;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC	glEnableVertexAttribArray;
extern PFNGLGENVERTEXARRAYSPROC			glGenVertexArrays;
extern PFNGLGETATTRIBLOCATIONPROC			glGetAttribLocation;
extern PFNGLVERTEXATTRIBPOINTERPROC		glVertexAttribPointer;
extern PFNGLBINDATTRIBLOCATIONPROC			glBindAttribLocation;
extern PFNGLGETUNIFORMLOCATIONPROC			glGetUniformLocation;
extern PFNGLUNIFORMMATRIX4FVPROC			glUniformMatrix4fv;
extern PFNGLACTIVETEXTUREPROC				glActiveTexture;
extern PFNGLUNIFORM1IPROC					glUniform1i;
extern PFNGLGENERATEMIPMAPPROC				glGenerateMipmap;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC	glDisableVertexAttribArray;
extern PFNGLUNIFORM3FVPROC					glUniform3fv;
extern PFNGLUNIFORM4FVPROC					glUniform4fv;

#endif