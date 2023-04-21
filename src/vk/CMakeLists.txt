set(SOURCE_FILES main.cpp HelloTriangleApplication.h HelloTriangleApplication.cpp)

set(PROJECT_NAME ${PROJECT_NAME}_vk)



find_package(Vulkan)

include_directories(${Vulkan_INCLUDE_DIRS})

link_directories(${Vulkan_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan)
