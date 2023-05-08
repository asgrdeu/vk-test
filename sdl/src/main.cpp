// /*
//     SDL2 Vulkan application
// */

// #if defined(_WIN32)
// #define SDL_MAIN_HANDLED
// #endif

// #include <SDL2/SDL.h>

// #include <iostream>

// using namespace std;

// SDL_Window *window;
// const std::string WINDOW_NAME = "SDL2 Vulkan application";

// int main(int argc, char **argv) {
//   if (SDL_Init(SDL_INIT_VIDEO))
//     cout << "Failed to initialize SDL2 with:  " << SDL_GetError() << endl;

//   window = SDL_CreateWindow(WINDOW_NAME.c_str(), SDL_WINDOWPOS_CENTERED,
//                             SDL_WINDOWPOS_CENTERED, 800, 600,
//                             SDL_WINDOW_SHOWN);

//   if (!window)
//     cout << "Failed to create window with: " << SDL_GetError() << endl;

//   SDL_Event event;
//   while (event.type != SDL_QUIT)
//     SDL_PollEvent(&event);

//   SDL_DestroyWindow(window);
//   SDL_Quit();
//   return 0;
// }

#include <SDL2/SDL.h>

#include <stddef.h>
#include <stdio.h>

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
