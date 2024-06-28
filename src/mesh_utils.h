#ifndef MESH_UTILS_H
#define MESH_UTILS_H

typedef struct Primitive Primitive;
struct Primitive {
  u32 startIndex;
  u32 numIndices;
  u32 startVertex;
  u32 numVertices;

  // TODO: shapes
};

typedef struct Group Group;
struct Group {
  bgfx_vertex_buffer_handle_t vbh;
  bgfx_index_buffer_handle_t ibh;
  u16 numVertices;
  u8* vertices;
  u32 numIndices;
  u16* indices;
  // TODO: shapes

  Primitive* prims;
  u32 primCount;
};

typedef struct Mesh Mesh;
struct Mesh {
  bgfx_vertex_layout_t layout;
  Group* groups;
  u32 groupCount;
};

local Mesh* mesh_load(const char* filePath);
local void mesh_unload(Mesh* mesh);
local void mesh_submit(bgfx_encoder_t* encoder,
                       const Mesh* mesh,
                       bgfx_view_id_t id,
                       bgfx_program_handle_t program,
                       Mat4 mtx,
                       u64 state);

#endif