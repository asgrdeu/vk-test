#include <iostream>
using namespace std;

#if defined (_WIN32)
#include <SDL.h>
<<<<<<< HEAD
#else  
=======
#else
>>>>>>> 7df74fa79c48ad1b32326e4a9f5dbbfcb807e581
#include <SDL2/SDL.h>
#endif

SDL_Window *window;
const std::string WINDOW_NAME = "SDL2 Vulkan application";

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(WINDOW_NAME.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);

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