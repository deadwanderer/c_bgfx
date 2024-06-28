#ifndef OS_CORE_H
#define OS_CORE_H


typedef u32 OS_AccessFlags;
enum {
  OS_AccessFlag_Read = (1 << 0),
  OS_AccessFlag_Write = (1 << 1),
  OS_AccessFlag_Execute = (1 << 2),
  OS_AccessFlag_Append = (1 << 3),
  OS_AccessFlag_ShareRead = (1 << 4),
  OS_AccessFlag_ShareWrite = (1 << 5),
};

root_function u64 OS_PageSize(void);

root_function void* OS_Reserve(u64 size);
root_function void OS_Release(void* ptr, u64 size);
root_function void OS_Commit(void* ptr, u64 size);
root_function void OS_Decommit(void* ptr, u64 size);
root_function void OS_Protect(void* ptr, u64 size, OS_AccessFlags flags);

#endif