set(SOURCE_FILES main.cpp)

cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME PROJECT_NAME)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)