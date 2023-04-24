<<<<<<< HEAD
#if defined (_WIN32)
#include <windows.h>
#include <SDL.h>
#include <io.h>
#include <stdio.h>
#include <fcntl.h>

=======
/*
    SDL2 Vulkan Test
*/

#include <SDL_log.h>
#if defined (_WIN32)
#include <SDL.h>
#include <Windows.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>
>>>>>>> 684f36b6c44778c7af714fa7e426640d8c9b2510
#else
#include <SDL2/SDL.h>
#endif

#include <iostream>
<<<<<<< HEAD
#include <cstdio>
=======
>>>>>>> 684f36b6c44778c7af714fa7e426640d8c9b2510
using namespace std;

#include <vulkan/vulkan.h>

SDL_Window *window;
const std::string WINDOW_NAME = "vk_sdl_test_2";

int main(int argc, char **argv) {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(WINDOW_NAME.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);

    

    

#if defined (_WIN32)
    // AllocConsole();

    // HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    // int hCrt = _open_osfhandle((long) handle_out, _O_TEXT);
    // FILE* hf_out = _fdopen(hCrt, "w");
    // setvbuf(hf_out, NULL, _IONBF, 1);
    // *stdout = *hf_out;
    
    printf_s("const char *const Format, ...", "nhbybyihbiub");

    // HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    // hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
    // FILE* hf_in = _fdopen(hCrt, "r");
    // setvbuf(hf_in, NULL, _IONBF, 128);
    // *stdin = *hf_in;

    //freopen( "output.txt", "w", stdout );
    // freopen_s( "error.txt", "w", stderr );

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    //cout << extensionCount << " extensions supported\n";
    //fclose(stdout);
#endif

    SDL_LogOutputFunction callback;
    SDL_LogSetOutputFunction(callback, nullptr);
    callback(nullptr, SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Hello world!");

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