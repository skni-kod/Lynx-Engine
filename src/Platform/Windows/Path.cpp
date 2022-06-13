#include "Platform/Generic/Path.h"

const wchar_t Path::os_separator = L'\\';
const wchar_t Path::invalid_path_symbols[] = {
	L'<',
	L'>',
	L':',
	L'"',
	L'/',
	L'\\',
	L'|',
	L'?',
	L'*',
};

Path::Path() : 
	is_relative(false),
	path_stack()
	{}

std::wstring Path::GetFileName() {
	return path_stack.top();
}