#include "Platform/Generic/Path.h"
#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>

const wchar_t Path::os_separator = L'\\';
const wchar_t Path::invalid_path_symbols[] = {
	'<',
	'>',
	':',
	'"',
	'/',
	'\\',
	'|',
	'?',
	'*',
};

Path::Path(const std::wstring& path) : path(path) {
	// todo is relative
}

Path Path::GetWorkingDirectory() {
	DWORD buf_len;
	LPWSTR path;

	buf_len = GetCurrentDirectory(0, NULL);

	path = (LPWSTR)malloc(buf_len);
	GetCurrentDirectory(buf_len, path);

	return Path(std::wstring(path));

	free(path);
}

Path Path::GetTempDirectory() {
	LPWSTR path;

	path = (LPWSTR)malloc(MAX_PATH);
	GetTempPath(MAX_PATH, path);

	return Path(std::wstring(path));

	free(path);
}

