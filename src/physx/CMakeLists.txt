set(SOURCE_FILES main.cpp)

cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME PROJECT_NAME)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS -fasm-blocks)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)