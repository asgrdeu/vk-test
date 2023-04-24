/*
    SDL2 Vulkan application
*/

#if defined (_WIN32)
#define SDL_MAIN_HANDLED
#endif

#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

#include <vulkan/vulkan.h>

#include <glm/glm.hpp>

SDL_Window *window;
const std::string WINDOW_NAME = "SDL2 Vulkan Test";

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(WINDOW_NAME.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    cout << "extensionCount: " << extensionCount << endl;

    // glm::mat4 matrix;
    // glm::vec4 vec;
    // auto test = matrix * vec;

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