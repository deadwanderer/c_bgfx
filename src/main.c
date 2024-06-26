#include "core.h"
#include "bgfx_math.h"

#include <SDL3/SDL.h>
#include <bgfx/c99/bgfx.h>
#include "shader_utils.h"

#include "bgfx_math.c"
#include "shader_utils.c"

int ScreenWidth = 1280;
int ScreenHeight = 720;
uint32_t debug = BGFX_DEBUG_TEXT | BGFX_DEBUG_STATS;
uint32_t reset = BGFX_RESET_VSYNC;

typedef struct PosColorVertex {
  f32 x;
  f32 y;
  f32 z;
  u32 abgr;
} PosColorVertex;

static bgfx_vertex_layout_t PosColorVertexLayout() {
  bgfx_vertex_layout_t result;
  bgfx_vertex_layout_begin(&result, bgfx_get_renderer_type());
  bgfx_vertex_layout_add(&result, BGFX_ATTRIB_POSITION, 3,
                         BGFX_ATTRIB_TYPE_FLOAT, false, false);
  bgfx_vertex_layout_add(&result, BGFX_ATTRIB_COLOR0, 4, BGFX_ATTRIB_TYPE_UINT8,
                         true, false);
  bgfx_vertex_layout_end(&result);
  return result;
}

local PosColorVertex cubeVertices[] = {
    {-1.0f, 1.0f, 1.0f, 0xFF000000},   {1.0f, 1.0f, 1.0f, 0xFF0000FF},
    {-1.0f, -1.0f, 1.0f, 0xFF00FF00},  {1.0f, -1.0f, 1.0f, 0xFF00FFFF},
    {-1.0f, 1.0f, -1.0f, 0xFFFF0000},  {1.0f, 1.0f, -1.0f, 0xFFFF00FF},
    {-1.0f, -1.0f, -1.0f, 0xFFFFFF00}, {1.0f, -1.0f, -1.0f, 0xFFFFFFFF},
};

local const u16 cubeTriList[] = {
    0, 1, 2, 1, 3, 2, 4, 6, 5, 5, 6, 7, 0, 2, 4, 4, 2, 6,
    1, 5, 3, 5, 7, 3, 0, 4, 1, 4, 5, 1, 2, 3, 6, 6, 3, 7,
};

local const u16 cubeTriStrip[] = {
    0, 1, 2, 3, 7, 1, 5, 0, 4, 2, 6, 7, 4, 5,
};

local const u16 cubeLineList[] = {
    0, 1, 0, 2, 0, 4, 1, 3, 1, 5, 2, 3, 2, 6, 3, 7, 4, 5, 4, 6, 5, 7, 6, 7,
};

local const u16 cubeLineStrip[] = {0, 2, 3, 1, 5, 7, 6, 4, 0,
                                   2, 6, 4, 5, 7, 3, 1, 0};

local const u16 cubePoints[] = {
    0, 1, 2, 3, 4, 5, 6, 7,
};

local const char* ptNames[] = {
    "Triangle List", "Triangle Strip", "Lines", "Line Strip", "Points",
};

local const u64 ptState[] = {
    UINT64_C(0),          BGFX_STATE_PT_TRISTRIP,
    BGFX_STATE_PT_LINES,  BGFX_STATE_PT_LINESTRIP,
    BGFX_STATE_PT_POINTS,
};

root_function char* renderer_type_to_string(bgfx_renderer_type_t type) {
  switch (type) {
    case BGFX_RENDERER_TYPE_NOOP: {
      return "NOOP";
    } break;
    case BGFX_RENDERER_TYPE_AGC: {
      return "AGC";
    } break;
    case BGFX_RENDERER_TYPE_DIRECT3D11: {
      return "DIRECT3D11";
    } break;
    case BGFX_RENDERER_TYPE_DIRECT3D12: {
      return "DIRECT3D12";
    } break;
    case BGFX_RENDERER_TYPE_GNM: {
      return "GNM";
    } break;
    case BGFX_RENDERER_TYPE_METAL: {
      return "METAL";
    } break;
    case BGFX_RENDERER_TYPE_NVN: {
      return "NVN";
    } break;
    case BGFX_RENDERER_TYPE_OPENGLES: {
      return "OPENGLES";
    } break;
    case BGFX_RENDERER_TYPE_OPENGL: {
      return "OPENGL";
    } break;
    case BGFX_RENDERER_TYPE_VULKAN: {
      return "VULKAN";
    } break;
    default: {
      return "";
    } break;
  }
}

int main(int argc, char* argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    return -1;
  }
  SDL_Window* window =
      SDL_CreateWindow("BGFX", ScreenWidth, ScreenHeight,
                       SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN);
  if (window == NULL) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return -1;
  }

  void* nwh = SDL_GetProperty(SDL_GetWindowProperties(window),
                              SDL_PROP_WINDOW_WIN32_HWND_POINTER, NULL);

  bgfx_init_t init;
  bgfx_init_ctor(&init);

  init.platformData.nwh = nwh;

  bgfx_init(&init);
  bgfx_reset((uint32_t)ScreenWidth, (uint32_t)ScreenHeight, reset,
             init.resolution.format);

  bgfx_set_debug(debug);

  bgfx_renderer_type_t renderers[BGFX_RENDERER_TYPE_COUNT];

  for (int i = 0; i < BGFX_RENDERER_TYPE_COUNT; i++) {
    renderers[i] = BGFX_RENDERER_TYPE_COUNT;
  }

  u8 renderer_count =
      bgfx_get_supported_renderers(BGFX_RENDERER_TYPE_COUNT, renderers);

  SDL_Log("Supported renderer count: %d\n", renderer_count);
  for (int i = 0; i < BGFX_RENDERER_TYPE_COUNT; i++) {
    if (renderers[i] == BGFX_RENDERER_TYPE_COUNT) {
      continue;
    }
    SDL_Log("\t%s", renderer_type_to_string(renderers[i]));
  }

  bgfx_set_view_clear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f,
                      0);

  bgfx_vertex_layout_t vert_layout = PosColorVertexLayout();

  bgfx_vertex_buffer_handle_t vbh = bgfx_create_vertex_buffer(
      bgfx_make_ref(cubeVertices, sizeof(cubeVertices)), &vert_layout, 0);

  bgfx_index_buffer_handle_t ibh[SDL_arraysize(ptState)];
  ibh[0] = bgfx_create_index_buffer(
      bgfx_make_ref(cubeTriList, sizeof(cubeTriList)), 0);
  ibh[1] = bgfx_create_index_buffer(
      bgfx_make_ref(cubeTriStrip, sizeof(cubeTriStrip)), 0);
  ibh[2] = bgfx_create_index_buffer(
      bgfx_make_ref(cubeLineList, sizeof(cubeLineList)), 0);
  ibh[3] = bgfx_create_index_buffer(
      bgfx_make_ref(cubeLineStrip, sizeof(cubeLineStrip)), 0);
  ibh[4] = bgfx_create_index_buffer(
      bgfx_make_ref(cubePoints, sizeof(cubePoints)), 0);

  bgfx_program_handle_t program = load_program("vs_cubes", "fs_cubes");

  SDL_ShowWindow(window);

  SDL_bool quit = false;
  while (!quit) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_EVENT_QUIT: {
          quit = true;
        } break;
        case SDL_EVENT_KEY_DOWN: {
          switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE: {
              quit = true;
            } break;
          }
        } break;
      }
    }

    bgfx_set_view_rect(0, 0, 0, (uint16_t)ScreenWidth, (uint16_t)ScreenHeight);

    bgfx_encoder_t* encoder = bgfx_encoder_begin(true);
    bgfx_encoder_touch(encoder, 0);
    bgfx_encoder_end(encoder);

    bgfx_dbg_text_clear(0, false);
    bgfx_dbg_text_printf(0, 2, 0x3f, "Test Text");
    bgfx_frame(false);
  }

  for (int i = 0; i < SDL_arraysize(ptState); i++) {
    bgfx_destroy_index_buffer(ibh[i]);
  }
  bgfx_destroy_vertex_buffer(vbh);
  bgfx_destroy_program(program);

  bgfx_shutdown();
  SDL_DestroyWindow(window);
  SDL_Quit();
}