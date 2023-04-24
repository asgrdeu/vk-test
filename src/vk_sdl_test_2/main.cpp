#include <SDL_log.h>
#include <iostream>
#include <stdio.h>
#include <fcntl.h>

using namespace std;

#if defined (_WIN32)
#include <SDL.h>

#include <Windows.h>
#include <io.h>

#else
#include <SDL2/SDL.h>
#endif

#include <vulkan/vulkan.h>

SDL_Window *window;
const std::string WINDOW_NAME = "vk_sdl_test_2";

int main(int argc, char **argv) {
     

    

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(WINDOW_NAME.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported\n";

#if defined (_WIN32)
    AllocConsole();

    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    int hCrt = _open_osfhandle((long) handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;

    printf("HIIIIIII");
#endif

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