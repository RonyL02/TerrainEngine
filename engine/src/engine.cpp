module;

#include <SDL3/SDL.h>
#include <iostream>

#include <stdexcept>
#include <string>
#include <string_view>

module engine;

namespace {
  std::runtime_error sdl_error(std::string_view action) {
    std::string message;
    message.reserve(action.size() + 32);
    message.append(action);
    message.append(" failed: ");
    message.append(SDL_GetError());
    return std::runtime_error{message};
  }
} // namespace

void engine::hello() { std::cout << "Hello enginee\n"; }

void engine::open_window() {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    throw sdl_error("SDL_Init");
  }

  SDL_Window *window =
      SDL_CreateWindow("Terrain Engine", 1280, 720, SDL_WINDOW_RESIZABLE);

  if (window == nullptr) {
    SDL_Quit();
    throw sdl_error("SDL_CreateWindow");
  }

  bool running = true;

  while (running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        running = false;
      }
    }

    SDL_Delay(16);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
}
