/*
    SDL2 Vulkan application
*/

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <stdint.h>
#include <string>

#if defined(_WIN32)
#define SDL_MAIN_HANDLED
#endif

// SDL2 includes
#include <SDL2/SDL.h>

// std includes
#include <iostream>
#include <vector>



using namespace std;


 int main() {
    int res;
    res = SDL_Init(SDL_INIT_EVERYTHING);
    printf("SDL_Init -> %d\n", res);

    if (res < 0) {
        printf("SDL_Init failed. err=%s\n", SDL_GetError());
        return 1;
    };

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    res = SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
    
    printf("SDL_CreateWindowAndRenderer -> %d\n", res);
    if (res < 0) {
        printf("SDL_CreateWindowAndRenderer failed. err=%s\n", SDL_GetError());
        return 1;
    }

    int running = 1;
    while (running) {
        SDL_Event event;
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event)) { ;
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }
        SDL_Delay(1);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

