set(SOURCE_FILES main.cpp)

set(PROJECT_NAME ${PROJECT_NAME}_winapi)

add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

#target_link_libraries(${PROJECT_NAME} PUBLIC msvcrtd)