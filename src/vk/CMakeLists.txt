set(SOURCE_FILES main.cpp HelloTriangleApplication.h HelloTriangleApplication.cpp)

set(PROJECT_NAME ${PROJECT_NAME}_vk)

#include_directories(${VULKAN_SDK}/include)
#link_directories(${VULKAN_SDK}/include)

find_package(Vulkan)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE vulkan)