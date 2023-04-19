set(SOURCE_FILES main.cpp)

set(PROJECT_NAME ${PROJECT_NAME}_sdl)

if (WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/src_sdl/include)
    link_directories(${CMAKE_SOURCE_DIR}/src_sdl/include)
elseif(UNIX)
    find_package(SDL2 REQUIRED)
endif()

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} PUBLIC SDL2)
    
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
endif()

message(${CMAKE_SOURCE_DIR}/src_sdl/include)