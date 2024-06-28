
#include "os/core/os_core.c"
#if OS_WINDOWS
#include "os/core/win32/os_core_win32.c"
#else 
#error OS layer not implemented
#endif
