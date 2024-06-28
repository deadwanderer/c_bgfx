#include <stdio.h>

local char* shader_base_path = "shaders";
local bgfx_shader_handle_t load_shader(const char* shader_name) {
  bgfx_shader_handle_t result = BGFX_INVALID_HANDLE;

  char buf[1024];
  char* subfolder = "";
  bgfx_renderer_type_t type = bgfx_get_renderer_type();
  switch (type) {
    case BGFX_RENDERER_TYPE_NOOP:
    case BGFX_RENDERER_TYPE_DIRECT3D11:
    case BGFX_RENDERER_TYPE_DIRECT3D12: {
      subfolder = "dx11/";
    } break;
    case BGFX_RENDERER_TYPE_OPENGL: {
      subfolder = "glsl/";
    } break;
    case BGFX_RENDERER_TYPE_VULKAN: {
      subfolder = "spirv/";
    } break;
    default: {
      SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Invalid Renderer Type: %d\n", type);
    }
  }
  int endchar = sprintf_s(buf, 1024, "%s/%s%s.bin", shader_base_path, subfolder,
                          shader_name);
  buf[endchar] = 0;

  FILE* f = fopen(buf, "rb");

  if (f == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to open shader file '%s'\n",
                 buf);
  } else {
    fseek(f, 0, SEEK_END);
    size_t file_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    void* data = malloc(file_size + 1);
    fread_s(data, file_size, file_size, 1, f);
    ((u8*)data)[file_size] = 0;

    result = bgfx_create_shader(bgfx_copy(data, (u32)file_size));
    free(data);
  }
  fclose(f);
  return result;
}

local bgfx_program_handle_t load_program(const char* shader_base_name) {
  char buf[1024];
  int endchar = sprintf_s(buf, 1024, "%s%s", "vs_", shader_base_name);
  buf[endchar] = 0;
  bgfx_shader_handle_t vsh = load_shader(buf);
  endchar = sprintf_s(buf, 1024, "%s%s", "fs_", shader_base_name);
  buf[endchar] = 0;
  bgfx_shader_handle_t fsh = load_shader(buf);

  return bgfx_create_program(vsh, fsh, true);
}