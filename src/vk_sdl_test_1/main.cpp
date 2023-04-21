#include <iostream>
using namespace std;

#if defined (_WIN32)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <vulkan/vulkan.h>

SDL_Window *window;
const std::string WINDOW_NAME = "SDL2 Vulkan application";

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(WINDOW_NAME.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported\n";
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