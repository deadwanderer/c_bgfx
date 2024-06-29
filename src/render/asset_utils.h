#ifndef ASSET_UTILS_H
#define ASSET_UTILS_H

typedef struct BinaryReader BinaryReader;
struct BinaryReader {
  u8* data;
  s64 pos;
  s64 dataLen;
};

local s32 BR_ReadBytes(BinaryReader* reader, void* out, int bytesToRead);
local s32 BR_ReadU16(BinaryReader* reader, u16* out);
local s32 BR_ReadU32(BinaryReader* reader, u32* out);
local s32 BR_ReadF32(BinaryReader* reader, f32* out);
local s32 BR_ReadVec3(BinaryReader* reader, Vec3* out);
local s32 BR_ReadMat4(BinaryReader* reader, Mat4* out);
local s32 BR_ReadAabb(BinaryReader* reader, Aabb* out);
local s32 BR_ReadObb(BinaryReader* reader, Obb* out);
local s32 BR_ReadSphere(BinaryReader* reader, Sphere* out);
local s32 BR_ReadVertexLayout(BinaryReader* reader, bgfx_vertex_layout_t* out);

typedef struct Primitive Primitive;
struct Primitive {
  u32 startIndex;
  u32 numIndices;
  u32 startVertex;
  u32 numVertices;

  Sphere sphere;
  Aabb aabb;
  Obb obb;
};

typedef struct Group Group;
struct Group {
  bgfx_vertex_buffer_handle_t vbh;
  bgfx_index_buffer_handle_t ibh;
  u16 numVertices;
  u8* vertices;
  u32 numIndices;
  u16* indices;

  Sphere sphere;
  Aabb aabb;
  Obb obb;

  Primitive* prims;
  u32 primCount;
};

typedef struct Mesh Mesh;
struct Mesh {
  Arena* arena;
  bgfx_vertex_layout_t layout;
  Group* groups;
  u32 groupCount;
};

local Mesh* mesh_load(Arena* arena, const char* fileName);
local void mesh_unload(Mesh* mesh);
local void mesh_submit(bgfx_encoder_t* encoder,
                       const Mesh* mesh,
                       bgfx_view_id_t id,
                       bgfx_program_handle_t program,
                       Mat4 mtx,
                       u64 state);

#endif