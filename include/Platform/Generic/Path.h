#if !defined(PATH_H)
#define PATH_H

#include <string>
#include <stack>

class Path {
public:
    Path();
    Path(std::wstring& path);

    std::wstring GetFileName();
    std::wstring GetExtension();


    static Path GetHomeDirectory();
    static Path GetDesktopDirectory();
    static Path GetConfigDirectory();
    static Path GetWorkingDirectory();
    static Path GetTempDirectory();

    static Path ChangeDirectory(Path&);

    static Path Join(Path*[]);
    static Path Join(Path&, Path&);
    static Path Join(Path&, Path&, Path&); // TODO: + operator?


private:
    std::stack<wchar_t*> path_stack;
    bool is_relative;


    const static wchar_t os_separator;
    const static wchar_t internal_separator;
    const static wchar_t invalid_path_symbols[];
};

const wchar_t Path::internal_separator = L'/';

#endif // PATH_H
