set(SOURCE_FILES main.cpp)

set(PROJECT_NAME ${PROJECT_NAME}_sdl)

if (WIN32)
    #include_directories(${CMAKE_SOURCE_DIR}/src_sdl/include)

    #link_directories(${CMAKE_SOURCE_DIR}/src_sdl/include)

    #set(SDL2_DIR ${CMAKE_SOURCE_DIR}/src_sdl)

    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
endif()

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

if(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
elseif(UNIX)
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif()

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

if (WIN32 AND TARGET SDL2::SDL2main)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)