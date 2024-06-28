#ifndef OS_INC_H
#define OS_INC_H

#ifndef ArenaImpl_Reserve
#define ArenaImpl_Reserve OS_Reserve
#endif
#ifndef ArenaImpl_Release
#define ArenaImpl_Release OS_Release
#endif
#ifndef ArenaImpl_Commit
#define ArenaImpl_Commit OS_Commit
#endif
#ifndef ArenaImpl_Decommit
#define ArenaImpl_Decommit OS_Decommit
#endif

#include "os/core/os_core.h"
#if OS_WINDOWS
#include "os/core/win32/os_core_win32.h"
#else 
#error OS layer not implemented
#endif

#endif