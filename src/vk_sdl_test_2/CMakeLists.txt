set(SOURCE_FILES main.cpp)

set(PROJECT_NAME ${PROJECT_NAME}_vk_sdl_test_2)

set(CMAKE_PREFIX_PATH "C:/glm/cmake/glm")

# Vulkan
find_package(Vulkan)

if(WIN32)
    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
endif()

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

# GLM
find_package(GLM REQUIRED)

if(WIN32)
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
    set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "")
elseif(UNIX)
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif()

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

if (WIN32 AND TARGET SDL2::SDL2main)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
endif()

# Vulkan
target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan)

# GLM
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)