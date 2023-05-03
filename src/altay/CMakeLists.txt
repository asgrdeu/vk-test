set(SOURCE_FILES main.cpp)

cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME PROJECT_NAME)

# GLM
set(glm_DIR ${CMAKE_SOURCE_DIR}/include/glm)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/include)

# Vulkan
find_package(Vulkan)

if(WIN32)
    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
endif()

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

# GLM
find_package(glm REQUIRED)

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