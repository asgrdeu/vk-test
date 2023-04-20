set(SOURCE_FILES main.cpp)

set(PROJECT_NAME ${PROJECT_NAME}_sdl)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
set(BUILD_SHARED_LIBS TRUE)


if (WIN32)

    include_directories(${CMAKE_SOURCE_DIR}/src_sdl/include)
    link_directories(${CMAKE_SOURCE_DIR}/src_sdl/include)
    set(SDL2_DIR ${CMAKE_SOURCE_DIR}/src_sdl)
    find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

elseif(UNIX)
    find_package(SDL2 REQUIRED)
endif()

add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})



target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

if (WIN32)
    if(TARGET SDL2::SDL2main)
    
        target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)

    endif()
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
    
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
endif()

message(${CMAKE_SOURCE_DIR}/src_sdl/include)