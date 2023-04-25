set(SOURCE_FILES main.cpp foo1.h foo2.h)

set(PROJECT_NAME ${PROJECT_NAME}_physx)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)