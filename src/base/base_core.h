#ifndef CORE_H
#define CORE_H

#include <stdint.h>
#include <string.h>

#define DeferLoop(start, end) \
  for (int _i_ = ((start), 0); _i_ == 0; _i_ += 1, (end))

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef float f32;
typedef double f64;

#define global static
#define root_function static
#define local static

#define MemoryCopy(dst, src, size) memcpy((dst), (src), (size))
#define MemoryMove(dst, src, size) memmove((dst), (src), (size))
#define MemorySet(dst, byte, size) memset((dst), (byte), (size))

#define MemoryCopyStruct(dst, src)            \
  do {                                        \
    Assert(sizeof(*(dst)) == sizeof(*(src))); \
    MemoryCopy((dst), (src), sizeof(*(dst))); \
  } while (0)

#define MemoryCopyArray(dst, src)          \
  do {                                     \
    Assert(sizeof(dst) == sizeof(src));    \
    MemoryCopy((dst), (src), sizeof(src)); \
  } while (0)

#define MemoryZero(ptr, size) MemorySet((ptr), 0, (size))
#define MemoryZeroStruct(ptr) MemoryZero((ptr), sizeof(*(ptr)))
#define MemoryZeroArray(arr) MemoryZero((arr), sizeof(arr))

#define UnusedVariable(name) (void)name

#define ArrayCount(a) (sizeof(a) / sizeof((a)[0]))

#define Bytes(n) (n)
#define Kilobytes(n) (n << 10)
#define Megabytes(n) (n << 20)
#define Gigabytes(n) (((u64)n) << 30)
#define Terabytes(n) (((u64)n) << 40)

#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Max(a, b) ((a) > (b) ? (a) : (b))

#if OS_WINDOWS
#define BreakDebugger() __debugbreak()
#else
#define BreakDebugger() (*(volatile int*)0 = 0)
#endif

#undef Assert
#if BUILD_DEBUG
#define Assert(b)      \
  do {                 \
    if (!(b)) {        \
      BreakDebugger(); \
    }                  \
  } while (0)
#else
#define Assert(b) ((void)(b))
#endif

#endif