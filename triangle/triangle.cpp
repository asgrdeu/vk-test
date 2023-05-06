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

// #define VK_INFO
#define VK_DEBUG

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
  }

  void initVulkan() {
    if (createInstance() != VK_SUCCESS) {
      throw std::runtime_error("failed to create instance");
    }
  }

  void mainLoop() {
    while (event.type != SDL_QUIT)
      SDL_PollEvent(&event);
  }

  void cleanup() {
    vkDestroyInstance(instance, nullptr);
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  VkResult createInstance() {
#ifdef VK_DEBUG
    if (initVulkanLayerValidation() != VK_SUCCESS) {
      throw std::runtime_error("failed to init Vulkan layer validation");
    }
#endif

#ifdef VK_INFO
    cout << "Finding Vulkan extensions" << endl;
#endif

    if (vkEnumerateInstanceExtensionProperties(
            nullptr, &extensionPropertiesCount, nullptr) != VK_SUCCESS) {
      throw std::runtime_error("failed to get extension count");
    }

#ifdef VK_INFO
    cout << "Extension count: " << extensionPropertiesCount << endl;
#endif

    extensionProperties.resize(extensionPropertiesCount);
    if (vkEnumerateInstanceExtensionProperties(
            nullptr, &extensionPropertiesCount, extensionProperties.data()) !=
        VK_SUCCESS) {
      throw std::runtime_error("failed to get extension properties");
    }

#ifdef VK_INFO
    cout << "Extension list:" << endl;

    for (uint32_t i = 0; i < extensionPropertiesCount; i++) {
      cout << i << " - "
           << "vkInstanceExtensionName: "
           << extensionProperties[i].extensionName << "; "
           << "Ext. version: " << extensionProperties[i].specVersion << endl;
    }
#endif

    // Enabled extensions validation
    uint32_t enabledExtensionCount = 0;
    for (auto &extension : extensionProperties)
      for (auto &enabledExtension : enabledExtensionNames)
        if (strcmp(extension.extensionName, enabledExtension) == 0)
          enabledExtensionCount++;

    if (enabledExtensionCount != enabledExtensionNames.size())
      throw std::runtime_error("not all Vulkan enabled extensions supported!");

#ifdef VK_INFO
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

#ifdef VK_INFO
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
    uint32_t validSdlExtensionCount = 0;
    for (auto &extension : extensionProperties) {
      for (auto &sdlExtension : sdlExtensionNames) {
        if (strcmp(extension.extensionName, sdlExtension) == 0) {
          validSdlExtensionCount++;
        }
      }
    }

    if (validSdlExtensionCount < sdlExtensionCount) {
      throw std::runtime_error("not all SDL extensions supported!");
    }

#ifdef VK_INFO
    cout << "All SDL extensions supported" << endl;
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

#ifdef VK_DEBUG
    vector<const char *> allEnabledExtensionNames;

    for (auto &extension : enabledExtensionNames)
      allEnabledExtensionNames.push_back(extension);

    for (auto &extension : sdlExtensionNames)
      allEnabledExtensionNames.push_back(extension);

    instanceCreateInfo.enabledLayerCount =
        static_cast<uint32_t>(validationLayers.size());
    instanceCreateInfo.ppEnabledLayerNames = validationLayers.data();
    instanceCreateInfo.enabledExtensionCount =
        static_cast<uint32_t>(allEnabledExtensionNames.size());
    instanceCreateInfo.ppEnabledExtensionNames =
        allEnabledExtensionNames.data();
#else
    instanceCreateInfo.enabledLayerCount = 0;
    instanceCreateInfo.ppEnabledLayerNames = nullptr;
    instanceCreateInfo.enabledExtensionCount = sdlExtensionCount;
    instanceCreateInfo.ppEnabledExtensionNames = sdlExtensionNames.data();
#endif

#ifdef VK_INFO
    cout << "Creating Vulkan instance" << endl;
#endif

    if (vkCreateInstance(&instanceCreateInfo, nullptr, &instance) !=
        VK_SUCCESS) {
      return VK_ERROR_INITIALIZATION_FAILED;
    }

#ifdef VK_INFO
    cout << "Successfuly to create Vulkan instance" << endl;
#endif

    return VK_SUCCESS;
  }

  VkResult initVulkanLayerValidation() {
#ifdef VK_INFO
    cout << "Finding supported validation layers" << endl;
#endif

    if (vkEnumerateInstanceLayerProperties(&layerPropertiesCount, nullptr) !=
        VK_SUCCESS) {
      throw std::runtime_error("failed to get layer count");
    }

#ifdef VK_INFO
    cout << "Layer count: " << layerPropertiesCount << endl;
#endif

    layerProperties.resize(layerPropertiesCount);
    if (vkEnumerateInstanceLayerProperties(
            &layerPropertiesCount, layerProperties.data()) != VK_SUCCESS) {
      throw std::runtime_error("failed to get layer properties");
    }

#ifdef VK_INFO
    cout << "Layer properties list:" << endl;

    for (uint32_t i = 0; i < layerPropertiesCount; i++) {
      cout << i << " - " << layerProperties[i].layerName << ";"
           << layerProperties[i].specVersion << endl;
    }

    cout << "Requested validation layers count: " << validationLayers.size()
         << endl;
    cout << "Requested validation layers list:" << endl;

    for (uint32_t i = 0; i < validationLayers.size(); i++) {
      cout << i << " - " << validationLayers[i] << endl;
    }

    cout << "Checking requested validation layers support" << endl;
#endif

    uint32_t availableLayerCount = 0;
    for (auto &layer : validationLayers) {
      for (auto &layerProperty : layerProperties) {
        if (strcmp(layer, layerProperty.layerName) == 0) {
          availableLayerCount++;
        }
      }
    }

    if (availableLayerCount != validationLayers.size()) {
      return VK_ERROR_LAYER_NOT_PRESENT;
    }

#ifdef VK_INFO
    cout << "All requested validation layers supported" << endl;
#endif

    return VK_SUCCESS;
  }

  static VKAPI_ATTR VkBool32 VKAPI_CALL
  debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                VkDebugUtilsMessageTypeFlagsEXT messageType,
                const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
                void *pUserData) {
    cout << "Validation layer: " << pCallbackData->pMessage << endl;
    return VK_FALSE;
  }

  // SDL2 Window
  SDL_Window *window;
  SDL_Event event;

  uint32_t sdlExtensionCount;
  vector<const char *> sdlExtensionNames;

  // Window dimensions
  const uint32_t WIDTH = 800;
  const uint32_t HEIGHT = 600;

  // Vulkan
  VkInstance instance;

  uint32_t extensionPropertiesCount;
  vector<VkExtensionProperties> extensionProperties;

  uint32_t layerPropertiesCount;
  vector<VkLayerProperties> layerProperties;

  const vector<const char *> validationLayers = {
      "VK_LAYER_KHRONOS_validation",
  };

  const vector<const char *> enabledExtensionNames = {
      VK_EXT_DEBUG_UTILS_EXTENSION_NAME};

  // Engine
  const string ENGINE_NAME = "Vulkan Engine";

  // Application
  const string APPLICATION_NAME = "Hello Triangle";
};

int main(int argc, char **argv) {
#ifdef VK_INFO
  print_version_info();
#endif

  HelloTriangleApplication app;

  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}