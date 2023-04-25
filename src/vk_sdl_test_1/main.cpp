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

// #define SDL_VK_INFO

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
    vkDestroyInstance(instance, nullptr);
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
  };

  void createInstance() {
#ifdef SDL_VK_INFO
    cout << "Creating instance" << endl;
    cout << "Finding Vulkan supported extensions" << endl;
#endif

    if (vkEnumerateInstanceExtensionProperties(nullptr, &extensionPropertyCount,
                                               nullptr) != VK_SUCCESS) {
      throw std::runtime_error("failed to get extension count");
    }

    extensionProperties.resize(extensionPropertyCount);
    if (vkEnumerateInstanceExtensionProperties(nullptr, &extensionPropertyCount,
                                               extensionProperties.data()) !=
        VK_SUCCESS) {
      throw std::runtime_error("failed to get extension properties");
    }

#ifdef SDL_VK_INFO
    cout << "Extension count: " << extensionPropertyCount << endl;
    cout << "Extension list:" << endl;

    for (uint32_t i = 0; i < extensionPropertyCount; i++) {
      cout << i << " - "
           << "vkInstanceExtensionName: "
           << extensionProperties[i].extensionName << "; "
           << "Ext. version: " << extensionProperties[i].specVersion << endl;
    }

    cout << "Finding SDL supported extensions" << endl;
#endif

    if (SDL_Vulkan_GetInstanceExtensions(window, &sdlExtensionCount, nullptr) !=
        SDL_TRUE) {
      throw std::runtime_error("failed to get SDL extension count");
    }

    sdlExtensionNames.resize(sdlExtensionCount);
    if (SDL_Vulkan_GetInstanceExtensions(
            window, &sdlExtensionCount, sdlExtensionNames.data()) != SDL_TRUE) {
      throw std::runtime_error("failed to get SDL extension list");
    }

#ifdef SDL_VK_INFO
    cout << "Extension count: " << sdlExtensionCount << endl;
    cout << "Extension list:" << endl;

    for (uint32_t i = 0; i < sdlExtensionCount; i++) {
      cout << i << " - "
           << "SDL_Vulkan_InstanceExtensionName: " << sdlExtensionNames[i]
           << endl;
    }

    cout << "Checking SDL supported extensions" << endl;
#endif

    // Extensions validation
    uint32_t validExtensionCount = 0;
    for (auto &extension : extensionProperties) {
      for (auto &sdlExtension : sdlExtensionNames) {
        if (strcmp(extension.extensionName, sdlExtension) == 0) {
          validExtensionCount++;
        }
      }
    }

    if (validExtensionCount < sdlExtensionCount) {
      throw std::runtime_error("not all SDL extensions supported!");
    }

#ifdef SDL_VK_INFO
    else {
      cout << "All SDL extensions supported" << endl;
    }
#endif

    VkApplicationInfo applicationInfo = {};
    applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    applicationInfo.pNext = nullptr;
    applicationInfo.pApplicationName = APPLICATION_NAME.c_str();
    applicationInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
    applicationInfo.pEngineName = ENGINE_NAME.c_str();
    applicationInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
    applicationInfo.apiVersion = VK_API_VERSION_1_3;

    VkInstanceCreateInfo instanceCreateInfo = {};
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pNext = nullptr;
    instanceCreateInfo.flags = 0;
    instanceCreateInfo.pApplicationInfo = &applicationInfo;
    instanceCreateInfo.enabledLayerCount = 0;
    instanceCreateInfo.ppEnabledLayerNames = nullptr;
    instanceCreateInfo.enabledExtensionCount = sdlExtensionCount;
    instanceCreateInfo.ppEnabledExtensionNames = sdlExtensionNames.data();

    if (vkCreateInstance(&instanceCreateInfo, nullptr, &instance) !=
        VK_SUCCESS) {
      throw std::runtime_error("failed to create instance!");
    }

#ifdef SDL_VK_INFO
    else {
      cout << "vkCreateInstance successful" << endl;
    }
#endif
  }

  // SDL2 Window
  SDL_Window *window;
  SDL_Event event;
  const uint32_t WIDTH = 800;
  const uint32_t HEIGHT = 600;

  // Vulkan
  VkInstance instance;
  uint32_t sdlExtensionCount;
  vector<const char *> sdlExtensionNames;
  uint32_t extensionPropertyCount;
  vector<VkExtensionProperties> extensionProperties;

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