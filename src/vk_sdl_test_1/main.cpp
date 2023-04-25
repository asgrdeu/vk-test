/*
    SDL2 Vulkan application
*/

#if defined(_WIN32)
#define SDL_MAIN_HANDLED
#endif

// SDL2 includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

// Vulkan includes
#include <vulkan/vulkan.h>

// GLM includes
#include <glm/glm.hpp>

// std includes
#include <iostream>
#include <vector>

using namespace std;

class HelloTriangleApplication {
public:
  void run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
  }

private:
  void initWindow() {
    SDL_Init(SDL_INIT_EVERYTHING);

    const string WINDOW_NAME = ENGINE_NAME + " - " + APPLICATION_NAME;

    window = SDL_CreateWindow(WINDOW_NAME.c_str(), SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,
                              SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);
  };

  void initVulkan() { createInstance(); };

  void mainLoop() {
    while (event.type != SDL_QUIT)
      SDL_PollEvent(&event);
  };

  void cleanup() {
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
  };

  void createInstance() {
    applicationInfo = {};
    applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    applicationInfo.pNext = nullptr;
    applicationInfo.pApplicationName = APPLICATION_NAME.c_str();
    applicationInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
    applicationInfo.pEngineName = ENGINE_NAME.c_str();
    applicationInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
    applicationInfo.apiVersion = VK_API_VERSION_1_3;

    instanceCreateInfo = {};
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pNext = nullptr;
    instanceCreateInfo.flags = 0;
    instanceCreateInfo.pApplicationInfo = &applicationInfo;
    instanceCreateInfo.enabledLayerCount = 0;
    instanceCreateInfo.ppEnabledLayerNames = nullptr;
    instanceCreateInfo.enabledExtensionCount = 0;
    instanceCreateInfo.ppEnabledExtensionNames = nullptr;
  }

  // SDL2 Window
  SDL_Window *window;
  SDL_Event event;
  const uint32_t WIDTH = 800;
  const uint32_t HEIGHT = 600;

  // Vulkan
  VkInstance instance;
  VkApplicationInfo applicationInfo;
  VkInstanceCreateInfo instanceCreateInfo;

  // Engine
  const string ENGINE_NAME = "Vulkan Engine";

  // Application
  const string APPLICATION_NAME = "Hello Triangle";
};

int main() {
  HelloTriangleApplication app;

  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}