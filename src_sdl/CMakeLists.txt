set(SOURCE_FILES main.cpp)

set(PROJECT_NAME ${PROJECT_NAME}_sdl)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
