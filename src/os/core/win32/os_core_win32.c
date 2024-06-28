
root_function u64 OS_PageSize(void) {
  SYSTEM_INFO info;
  GetSystemInfo(&info);
  return info.dwPageSize;
}

root_function void* OS_Reserve(u64 size) {
  u64 gb_snapped_size = size;
  gb_snapped_size += Gigabytes(1) - 1;
  gb_snapped_size -= gb_snapped_size % Gigabytes(1);
  void* ptr = VirtualAlloc(0, gb_snapped_size, MEM_RESERVE, PAGE_NOACCESS);
  return ptr;
}

root_function void OS_Release(void* ptr, u64 size) {
  UnusedVariable(size);
  VirtualFree(ptr, 0, MEM_RELEASE);
}

root_function void OS_Commit(void* ptr, u64 size) {
  u64 page_snapped_size = size;
  page_snapped_size += OS_PageSize() - 1;
  page_snapped_size -= page_snapped_size % OS_PageSize();
  VirtualAlloc(ptr, page_snapped_size, MEM_COMMIT, PAGE_READWRITE);
}

root_function void OS_Decommit(void* ptr, u64 size) {
  VirtualFree(ptr, size, MEM_DECOMMIT);
}

root_function void OS_Protect(void* ptr, u64 size, OS_AccessFlags flags) {
  u64 page_snapped_size = size;
  page_snapped_size += OS_PageSize() - 1;
  page_snapped_size -= page_snapped_size % OS_PageSize();

  DWORD new_flags = 0;
  {
    switch (flags) {
      default: {
        new_flags = PAGE_NOACCESS;
      } break;
#define Map(win32_code, bitflags) \
  case bitflags: {                \
    new_flags = win32_code;       \
  } break
        Map(PAGE_EXECUTE, OS_AccessFlag_Execute);
        Map(PAGE_EXECUTE_READ, OS_AccessFlag_Execute | OS_AccessFlag_Read);
        Map(PAGE_EXECUTE_READWRITE,
            OS_AccessFlag_Execute | OS_AccessFlag_Read | OS_AccessFlag_Write);
        Map(PAGE_EXECUTE_WRITECOPY,
            OS_AccessFlag_Execute | OS_AccessFlag_Write);
        Map(PAGE_READONLY, OS_AccessFlag_Read);
        Map(PAGE_READWRITE, OS_AccessFlag_Read | OS_AccessFlag_Write);
#undef Map
    }
  }

  DWORD old_flags = 0;
  VirtualProtect(ptr, page_snapped_size, new_flags, &old_flags);
}
