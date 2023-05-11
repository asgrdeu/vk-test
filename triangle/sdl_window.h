
#include <SDL.h>

#include <cstdint>
#include <string>
#include <vector>

namespace os {
class Window {
public:
  Window();
  ~Window();

  std::vector<const char *> getVulkanInstanceExtensionsNames();

private:
  SDL_Window *window;
  const std::string NAME = "sdl_window_impl";
  const uint32_t WIDTH = 800;
  const uint32_t HEIGHT = 600;
};
} // namespace os