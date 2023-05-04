file(GLOB PROJECT_PATH_LIST LIST_DIRECTORIES true [a-z]*)

foreach(PROJECT_PATH ${PROJECT_PATH_LIST})
    cmake_path(GET PROJECT_PATH FILENAME PROJECT_DIR_NAME)

    foreach(ENABLE_PROJECT ${ENABLE_PROJECT_LIST})
        if(${PROJECT_DIR_NAME} STREQUAL ${ENABLE_PROJECT})
            add_subdirectory(${ENABLE_PROJECT})
            message("PROJECT_ENABLED: " ${ENABLE_PROJECT})
        endif()
    endforeach()
endforeach()
