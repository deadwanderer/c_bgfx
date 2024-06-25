#include "core.h"
#include "bgfx_math.h"

#include <SDL3/SDL.h>
#include <bgfx/c99/bgfx.h>

#include "bgfx_math.c"

int ScreenWidth = 1280;
int ScreenHeight = 720;
uint32_t debug = BGFX_DEBUG_TEXT;
uint32_t reset = BGFX_RESET_VSYNC;

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

  bgfx_set_view_clear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f,
                      0);

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

  bgfx_shutdown();
  SDL_DestroyWindow(window);
  SDL_Quit();
}