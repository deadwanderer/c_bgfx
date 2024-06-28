local Mesh* mesh_load(const char* filePath) {
  return NULL;
}

local void mesh_unload(Mesh* mesh) {}

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
