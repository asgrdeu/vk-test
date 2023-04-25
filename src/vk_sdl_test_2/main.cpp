/*
    SDL2 Vulkan application
*/

#include <stdlib.h>
<<<<<<< HEAD
#include <vulkan/vulkan_core.h>
=======

>>>>>>> refs/remotes/origin/dev
#if defined(_WIN32)
#define SDL_MAIN_HANDLED
#endif

#include "triangl.h"
<<<<<<< HEAD
#include <SDL2/SDL_vulkan.h>
=======
// #include <SDL2/SDL.h>
>>>>>>> refs/remotes/origin/dev

using namespace std;

#include <vulkan/vulkan.h>

#include <glm/glm.hpp>

SDL_Window *window;
const std::string WINDOW_NAME = "SDL2 Vulkan Test";

int main() {
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow(
      WINDOW_NAME.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,
      600, SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

<<<<<<< HEAD
  TriangleApplication app;

=======
  // uint32_t extensionCount = 0;
  // vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
  // cout << "extensionCount: " << extensionCount << endl;

  TriangleApplication app;

>>>>>>> refs/remotes/origin/dev
  try {
    app.run();
  } catch (const std::exception &e) {
    cout << e.what() << endl;
    return EXIT_FAILURE;
  }
  // return EXIT_SUCCESS;
<<<<<<< HEAD
  VkApplicationInfo appInfo = {};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Triangle Application";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

    unit32_t sdlExtensionCount = 0;

  SDL_Vulkan_CreateSurface(window, VkInstance, VkSurfaceKHR);
  SDL_Vulkan_GetInstanceExtensions(window, &pCount, & );
  

=======
>>>>>>> refs/remotes/origin/dev
  SDL_Event event;
  bool running = true;
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }
  }

  SDL_DestroyWindow(window);
  window = nullptr;

  SDL_Quit();
  return 0;
}