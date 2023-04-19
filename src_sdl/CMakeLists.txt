set(SOURCE_FILES main.cpp)

set(PROJECT_NAME ${PROJECT_NAME}_sdl)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
