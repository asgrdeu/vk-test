#pragma once

#include <SDL2/SDL.h>
#include <vulkan/vulkan.h>

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vulkan/vulkan_core.h>


class TriangleApplication {
<<<<<<< HEAD
    public:
        void run(){
            
            initVulkan();
            mainLoop();
            cleanUp();
        }
        
    private:
        VkInstance instance;
        

        void initVulkan(){
            
            creatInstance();
        }
        
        void creatInstance(){
            
        }

        void mainLoop(){
=======
public:
  void run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanUp();
  }

private:
  void initWindow() {
    // SDL_Window *window;
    // const std::string WINDOW_NAME = "SDL2 Vulkan Test";
    // SDL_Init(SDL_INIT_EVERYTHING);
    // window =
    // SDL_CreateWindow(WINDOW_NAME.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_VULKAN
    // | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  }

  void initVulkan() {}
>>>>>>> refs/remotes/origin/dev

  void mainLoop() {}

  void cleanUp() {}
};