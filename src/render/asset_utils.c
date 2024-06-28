#include <stdio.h>

local char* asset_folder = "assets";
local char* mesh_folder = "meshes";
local char* texture_folder = "textures";

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

  u8* data = (u8*)fileData;

  Mesh* mesh = PushArrayNoZero(arena, Mesh, 1);
  mesh->arena = arena;

  // TODO: Ready to start file parsing.
  // https://github.com/bkaradzic/bgfx/blob/master/examples/common/bgfx_utils.cpp#L380

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
