/*
    SDL2 Vulkan application
*/

#if defined(_WIN32)
#define SDL_MAIN_HANDLED
#endif

#include <SDL2/SDL.h>

#include <iostream>

using namespace std;

SDL_Window *window;
const std::string WINDOW_NAME = "SDL2 Vulkan application";

int main(int argc, char **argv) {
  if (SDL_Init(SDL_INIT_VIDEO))
    cout << "Failed to initialize SDL2 with:  " << SDL_GetError() << endl;

  window = SDL_CreateWindow(WINDOW_NAME.c_str(), SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 800, 600,
                            SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);

  if (window)
    cout << "Failed to create window with: " << SDL_GetError() << endl;

  SDL_Event event;
  while (event.type != SDL_QUIT)
    SDL_PollEvent(&event);

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}