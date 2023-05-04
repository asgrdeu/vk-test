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

// Debug layers
#include <cstring>

using namespace std;

const std::vector<const char *> validationLayers = {
    "VK_LAYER_KHRONOS_validation"};

#define DEBUG

class VulkanTriangle {
public:
  void run() {
    initWindow();
    //getRequiredExtensions();
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

  void initVulkan() { createInstance(); }

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

  // void getRequiredExtensions() {
  //     std::vector<const char *> getRequiredExtensions()
  //         uint32_t sdlExtensionCount = 0;
  //     }
  //}

  // Vulkan instance
  void createInstance() {

    uint32_t sdlExtensionCount = 0;
    SDL_Vulkan_GetInstanceExtensions(window, &sdlExtensionCount, nullptr);

    vector<const char *> sdlExtensions;
    sdlExtensions.resize(sdlExtensionCount);
    SDL_Vulkan_GetInstanceExtensions(window, &sdlExtensionCount, sdlExtensions.data());
    
    for (uint32_t i = 0; i < sdlExtensionCount; i++) {
      cout << sdlExtensions[i] << endl;
    }

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount,
                                           extensions.data());

    std::cout << "Available extensions: \n" << std::endl;

    for (const auto &extension : extensions) {
      std::cout << '\t' << extension.extensionName << '\n';
    }

    // if (enableValidationLayers && !checkValidationLayerSupport()) {
    //   throw std::runtime_error(
    //       "validation layers requested, but not available!");
    // }

    

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

    // if (enableValidationLayers) {
    //   createInfo.enabledLayerCount =
    //       static_cast<uint32_t>(validationLayers.size());
    //   createInfo.ppEnabledLayerNames = validationLayers.data();
    // } else {
    //   createInfo.enabledLayerCount = 0;
    // }

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
      throw std::runtime_error("failed to create instance!");
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

#ifdef DEBUG
  const bool enableValidationLayers = true;
#else
  const bool enableValidationLayers = false;
#endif

  bool checkValidationLayerSupport() {
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    for (const char *layerName : validationLayers) {
      bool layerFound = false;
      for (const auto &layerProperties : availableLayers) {
        if (strcmp(layerName, layerProperties.layerName) == 0) {
          layerFound = true;
          break;
        }
      }

      if (!layerFound) {
        return false;
      }
    }
    return true;
  }

  // GLM
};

// main
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
