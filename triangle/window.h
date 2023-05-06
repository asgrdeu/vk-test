#pragma once

#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <SDL2/SDL.h>

namespace engine {
namespace os {
class Window;

struct WindowProperties {
    const char *title;
    int width;
    int height;
    
};

Window *createWindow(const WindowProperties &props);

} // namespace os
} // namespace engine

#endif // _WINDOW_H_