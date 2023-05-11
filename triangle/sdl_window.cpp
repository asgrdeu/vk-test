#include "sdl_window.h"

#include <SDL.h>
#include <SDL_vulkan.h>

#include <stdexcept>
#include <string>

namespace os {
Window::Window() {
  if (SDL_Init(SDL_INIT_EVERYTHING))
    throw std::runtime_error("SDL_Init failed with:  " +
                             std::string(SDL_GetError()));

  this->window = SDL_CreateWindow(NAME.c_str(), SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,
                                  SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);

  if (!this->window)
    throw std::runtime_error("SDL_CreateWindow failed with:  " +
                             std::string(SDL_GetError()));
}

Window::~Window() {
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}

std::vector<const char *> Window::getVulkanInstanceExtensionsNames() {
  uint32_t count = 0;
  if (SDL_Vulkan_GetInstanceExtensions(this->window, &count, nullptr) !=
      SDL_TRUE)
    throw std::runtime_error("SDL_Vulkan_GetInstanceExtensions failed with:  " +
                             std::string(SDL_GetError()));

  std::vector<const char *> extensions(count);
  if (SDL_Vulkan_GetInstanceExtensions(this->window, &count,
                                       extensions.data()) != SDL_TRUE)
    throw std::runtime_error("SDL_Vulkan_GetInstanceExtensions failed with:  " +
                             std::string(SDL_GetError()));

  return extensions;
}
} // namespace os