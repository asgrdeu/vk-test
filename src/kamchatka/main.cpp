/*
    SDL2 Vulkan application
*/

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <stdint.h>
#include <string>
#include <vulkan/vulkan_core.h>
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

class VulkanTriangle {
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

    const string WINDOW_NAME = ENGINE_NAME + " - " + " Vulkan Triangle";

    window = SDL_CreateWindow(
        WINDOW_NAME.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  }

  void initVulkan() {
    createInstance();
    uint32_t sdlExtensionCount = 0;
    const char **sdlExtensions;
    SDL_Vulkan_GetInstanceExtensions(window, &sdlExtensionCount, nullptr);
    SDL_Vulkan_GetInstanceExtensions(window, &sdlExtensionCount, sdlExtensions);
    for (uint32_t i = 0; i < sdlExtensionCount; i++) {
      cout << sdlExtensions[i] << endl;
    }
  }

  void mainLoop() {
    while (event.type != SDL_QUIT)
      SDL_PollEvent(&event);
  }

  void cleanup() {
    vkDestroyInstance(instance, nullptr);
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
  }

  void createInstance() {
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan SDL2 Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "Kamchatka";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledExtensionCount = 0;
    createInfo.ppEnabledExtensionNames = nullptr;
    createInfo.enabledLayerCount = 0;
    createInfo.ppEnabledLayerNames = nullptr;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
      throw std::runtime_error("failed to create instance!");
    }

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
    std::cout << "Available extensions: \n" << std::endl;
    for (const auto &extension : extensions) {
        std::cout << '\t' << extension.extensionName << '\n';
    }
  
  
  }
  // Vulkan

  VkInstance instance;

  // SDL2

  SDL_Window *window;
  SDL_Event event;
  const uint32_t WIDTH = 800;
  const uint32_t HEIGHT = 600;
  const string ENGINE_NAME = "Kamchatka";
  // GLM
};

int main() {
  VulkanTriangle app;
  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
