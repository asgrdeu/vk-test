/*
    SDL2 Vulkan Test
*/

#include <SDL_video.h>
#if defined (_WIN32)
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_log.h>

#include <Windows.h>

#include <fcntl.h>
#include <stdio.h>
#include <io.h>
#else
#include <SDL2/SDL.h>
#endif

#include <iostream>
#include <cstdio>
using namespace std;

#include <vulkan/vulkan.h>

SDL_Window *window;
const std::string WINDOW_NAME = "vk_sdl_test_2";

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(WINDOW_NAME.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    cout << "extensionCount: " << extensionCount << endl;

    SDL_Event event;
    bool running = true;
    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            }
        }
    }   

    SDL_DestroyWindow(window);
    window = nullptr;

    SDL_Quit();
    return 0;
}