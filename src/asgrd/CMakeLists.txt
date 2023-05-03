cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME PROJECT_NAME)

# GLM
set(glm_DIR ${CMAKE_SOURCE_DIR}/include/glm)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/include)

find_package(glm REQUIRED)

# Vulkan
find_package(Vulkan)

if (WIN32)
    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
endif()

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

file(GLOB SOURCE_FILES *.cpp)
file(GLOB HEADER_FILES *.h)

message("List of founded source files:")

foreach(FILE ${SOURCE_FILES})
    message(${FILE})
endforeach()

if(WIN32)
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
    set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "")
elseif(UNIX)
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif()

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

if (WIN32 AND TARGET SDL2::SDL2main)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

# Vulkan
target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan)

# GLM
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)