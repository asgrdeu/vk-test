cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME PROJECT_NAME)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include)
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS -fasm-blocks)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)