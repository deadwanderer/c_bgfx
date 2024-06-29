#include <stdio.h>

local char* asset_folder = "assets";
local char* mesh_folder = "meshes";
local char* texture_folder = "textures";

#define MAKEFOURCC(a, b, c, d) \
  (((u32)(a) | ((u32)(b) << 8) | ((u32)(c) << 16) | ((u32)(d) << 24)))

#define ChunkVertexBuffer MAKEFOURCC('V', 'B', ' ', 0x1)
#define ChunkVertexBufferCompressed MAKEFOURCC('V', 'B', 'C', 0x0)
#define ChunkIndexBuffer MAKEFOURCC('I', 'B', ' ', 0x0)
#define ChunkIndexBufferCompressed MAKEFOURCC('I', 'B', 'C', 0x1)
#define ChunkPrimitive MAKEFOURCC('P', 'R', 'I', 0x0)

local Mesh* mesh_load(Arena* arena, const char* fileName) {
  Arena* fileArena = ArenaAlloc(Gigabytes(2));
  char buf[1024];
  int endchar = sprintf_s(buf, sizeof(buf), "%s/%s/%s.bin", asset_folder,
                          mesh_folder, fileName);
  buf[endchar] = 0;

  FILE* file = fopen(buf, "rb");
  if (file == NULL) {
    fprintf(stderr, "Unable to open mesh file '%s'\n", buf);
    ArenaRelease(fileArena);
    return NULL;
  }
  fseek(file, 0, SEEK_END);
  size_t fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  void* fileData = ArenaPushNoZero(fileArena, (u64)fileSize + 1);
  fread_s(fileData, fileSize, fileSize, 1, file);
  fclose(file);
  ((u8*)fileData)[fileSize] = 0;

  BinaryReader reader = {0};
  reader.data = (u8*)fileData;
  reader.pos = 0;
  reader.dataLen = (s64)fileSize;

  Mesh* mesh = PushArrayNoZero(arena, Mesh, 1);
  mesh->arena = arena;

  // TODO: Ready to start file parsing.
  // https://github.com/bkaradzic/bgfx/blob/master/examples/common/bgfx_utils.cpp#L380

  Group group;
  u32 chunk;

  int idx = 0;
  bool parsing = true;

  while (parsing) {
    BR_ReadU32(&reader, &chunk);
    switch (chunk) {
      case ChunkVertexBuffer: {
        SDL_Log("Vertex buffer chunk");
        BR_ReadSphere(&reader, &group.sphere);
        BR_ReadAabb(&reader, &group.aabb);
        BR_ReadObb(&reader, &group.obb);

        BR_ReadVertexLayout(&reader, &mesh->layout);

        u16 stride = mesh->layout.stride;

        BR_ReadU16(&reader, &group.numVertices);

        u32 memSize = group.numVertices * stride;

        void* mem = ArenaPushNoZero(arena, memSize);
        BR_ReadBytes(&reader, mem, memSize);

        group.vbh = bgfx_create_vertex_buffer(bgfx_make_ref(mem, memSize),
                                              &mesh->layout, BGFX_BUFFER_NONE);
      } break;
      case ChunkVertexBufferCompressed: {
        SDL_Log("Compressed vertex buffer chunk");
      } break;
      case ChunkIndexBuffer: {
        SDL_Log("Index buffer chunk");
      } break;
      case ChunkIndexBufferCompressed: {
        SDL_Log("Compressed index buffer chunk");
      } break;
      case ChunkPrimitive: {
        SDL_Log("Primitive chunk");
      } break;
      default: {
        SDL_Log("Unknown chunk value %d\n", chunk);
        parsing = false;
      }
    }
  }

  ArenaRelease(fileArena);
  return mesh;
}

local void mesh_unload(Mesh* mesh) {
  // ArenaRelease(mesh->arena, mesh->groups);
  // mesh->arena = 0;
}

local void mesh_submit(bgfx_encoder_t* encoder,
                       const Mesh* mesh,
                       bgfx_view_id_t id,
                       bgfx_program_handle_t program,
                       Mat4 mtx,
                       u64 state) {
  // u64 state = 0 | BGFX_STATE_WRITE_MASK | BGFX_STATE_DEPTH_TEST_LESS |
  //             BGFX_STATE_CULL_CW | BGFX_STATE_MSAA;

  // bgfx_encoder_set_transform(encoder, rot.Elements, 1);

  // bgfx_encoder_set_vertex_buffer(encoder, 0, vbh, 0, UINT32_MAX);
  // bgfx_encoder_set_index_buffer(encoder, frame_ibh, 0, UINT32_MAX);
  // bgfx_encoder_set_state(encoder, state, 0);
  // bgfx_encoder_submit(encoder, 0, program, 0, BGFX_DISCARD_ALL);
}

local s32 BR_ReadBytes(BinaryReader* reader, void* out, int bytesToRead) {
  if (!(reader->pos + bytesToRead < reader->dataLen)) {
    return 0;
  }
  MemoryCopy(out, (void*)reader->data[reader->pos], bytesToRead);
  reader->pos += bytesToRead;
  return bytesToRead;
}

local s32 BR_ReadU16(BinaryReader* reader, u16* out) {
  if (!(reader->pos + sizeof(u16) < reader->dataLen)) {
    return 0;
  }
  *out = (u16)((u16*)reader->data)[reader->pos];
  reader->pos += sizeof(u16);
  return sizeof(u16);
}

local s32 BR_ReadU32(BinaryReader* reader, u32* out) {
  if (!(reader->pos + sizeof(u32) < reader->dataLen)) {
    return 0;
  }
  *out = (u32)((u32*)reader->data)[reader->pos];
  reader->pos += sizeof(u32);
  return sizeof(u32);
}

local s32 BR_ReadF32(BinaryReader* reader, f32* out) {
  if (!(reader->pos + sizeof(f32) < reader->dataLen)) {
    return 0;
  }
  *out = (f32)((f32*)reader->data)[reader->pos];
  reader->pos += sizeof(f32);
  return sizeof(f32);
}

local s32 BR_ReadVec3(BinaryReader* reader, Vec3* out) {
  if (!(reader->pos + sizeof(Vec3) < reader->dataLen)) {
    return 0;
  }
  BR_ReadF32(reader, &out->X);
  BR_ReadF32(reader, &out->Y);
  BR_ReadF32(reader, &out->Z);
  return sizeof(Vec3);
}

local s32 BR_ReadVec4(BinaryReader* reader, Vec4* out) {
  if (!(reader->pos + sizeof(Vec4) < reader->dataLen)) {
    return 0;
  }
  BR_ReadF32(reader, &out->X);
  BR_ReadF32(reader, &out->Y);
  BR_ReadF32(reader, &out->Z);
  BR_ReadF32(reader, &out->W);
  return sizeof(Vec4);
}

local s32 BR_ReadMat4(BinaryReader* reader, Mat4* out) {
  if (!(reader->pos + sizeof(Mat4) < reader->dataLen)) {
    return 0;
  }
  for (int i = 0; i < 4; i++) {
    Vec4* vec = &out->Columns[i];
    BR_ReadVec4(reader, vec);
  }
  return sizeof(Mat4);
}

local s32 BR_ReadAabb(BinaryReader* reader, Aabb* out) {
  if (!(reader->pos + sizeof(Aabb) < reader->dataLen)) {
    return 0;
  }
  BR_ReadVec3(reader, &out->min);
  BR_ReadVec3(reader, &out->max);
  return sizeof(Aabb);
}

local s32 BR_ReadObb(BinaryReader* reader, Obb* out) {
  if (!(reader->pos + sizeof(Obb) < reader->dataLen)) {
    return 0;
  }
  BR_ReadMat4(reader, &out->mtx);
  return sizeof(Obb);
}

local s32 BR_ReadSphere(BinaryReader* reader, Sphere* out) {
  if (!(reader->pos + sizeof(Sphere) < reader->dataLen)) {
    return 0;
  }
  BR_ReadVec3(reader, &out->center);
  BR_ReadF32(reader, &out->radius);
  return sizeof(Sphere);
}

local s32 BR_ReadVertexLayout(BinaryReader* reader, bgfx_vertex_layout_t* out) {
  if (!(reader->pos + sizeof(bgfx_vertex_layout_t) < reader->dataLen)) {
    return 0;
  }
  MemoryCopy(out, &reader->data[reader->pos], sizeof(bgfx_vertex_layout_t));
  reader->pos += sizeof(bgfx_vertex_layout_t);
  return sizeof(bgfx_vertex_layout_t);
}