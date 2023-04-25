/*
    SDL2 Vulkan application
*/

#if defined(_WIN32)
#define SDL_MAIN_HANDLED
#endif

// SDL2 includes
#include <SDL2/SDL.h>

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

    window = SDL_CreateWindow(WINDOW_NAME.c_str(), SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,
                              SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);
  };

  void initVulkan(){};

  void mainLoop() {
    while (event.type != SDL_QUIT)
      SDL_PollEvent(&event);
  };

  void cleanup(){
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
  };

  SDL_Window *window;
  SDL_Event event;
  const string WINDOW_NAME = "vk_sdl_test_1";
  const uint32_t WIDTH = 800;
  const uint32_t HEIGHT = 600;
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