#ifndef BASE_MEMORY_H
#define BASE_MEMORY_H

#ifndef ARENA_COMMIT_GRANULARITY
#define ARENA_COMMIT_GRANULARITY Kilobytes(4)
#endif

#ifndef ARENA_DECOMMIT_THRESHOLD
#define ARENA_DECOMMIT_THRESHOLD Megabytes(64)
#endif

typedef struct Arena Arena;
struct Arena {
  u64 pos;
  u64 commit_pos;
  u64 align;
  u64 size;
  Arena* ptr;
  u64 _unused[3];
};

typedef struct Temp Temp;
struct Temp {
  Arena* arena;
  u64 pos;
};

root_function Arena* ArenaAlloc(u64 size);
root_function Arena* ArenaAllocDefault(void);
root_function void ArenaRelease(Arena* arena);
root_function void* ArenaPushNoZero(Arena* arena, u64 size);
root_function void* ArenaPushAligned(Arena* arena, u64 alignment);
root_function void* ArenaPush(Arena* arena, u64 size);
root_function void ArenaPopTo(Arena* arena, u64 pos);
root_function void ArenaSetAutoAlign(Arena* arena, u64 align);
root_function void ArenaPop(Arena* arena, u64 size);
root_function void ArenaClear(Arena* arena);
root_function u64 ArenaPos(Arena* arena);

#define PushArrayNoZero(arena, type, count) \
  (type*)ArenaPushNoZero((arena), sizeof(type) * (count))
#define PushArray(arena, type, count) \
  (type*)ArenaPush((arena), sizeof(type) * (count))

root_function Temp TempBegin(Arena* arena);
root_function void TempEnd(Temp temp);

#define ArenaTempBlock(arena, name) \
  Temp name = {0};                  \
  DeferLoop(name = TempBegin(arena), TempEnd(name))

#endif