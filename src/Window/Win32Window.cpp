// te długie makra można by przenieść do osobnego nagłówka w przyszłości...
#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__CYGWIN__) || defined(__CYGWIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#include "../../include/Window.h"
#error
#endif