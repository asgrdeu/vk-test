#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vulkan/vulkan_core.h>

#include "HelloTriangleApplication.h"


int main() {
    HelloTriangleApplication app;

    VkBufferViewCreateInfo bufferViewCreateInfo = {};

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

