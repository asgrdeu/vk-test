<<<<<<< HEAD
#add_subdirectory(physx)
#add_subdirectory(sdl)
if(UNIX)
add_subdirectory(vk_sdl_test_1)
add_subdirectory(kamchatka)
elseif(WIN32)
add_subdirectory(altay)
endif()
=======
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
>>>>>>> refs/remotes/origin/dev
