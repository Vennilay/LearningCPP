cmake_minimum_required(VERSION 3.20)
project(LearningCPP)

set(CMAKE_CXX_STANDARD 17)

file(COPY ${CMAKE_SOURCE_DIR}/files/
        DESTINATION ${CMAKE_BINARY_DIR}/files/)

file(GLOB_RECURSE ALL_CPP_FILES
        "homework/*.cpp"
)

foreach(CPP_FILE ${ALL_CPP_FILES})
    file(RELATIVE_PATH REL_PATH ${CMAKE_SOURCE_DIR} ${CPP_FILE})

    string(REGEX REPLACE "[/\\\\]" "_" TARGET_NAME "${REL_PATH}")
    string(REGEX REPLACE "[ ]" "_" TARGET_NAME "${TARGET_NAME}")
    string(REPLACE ".cpp" "" TARGET_NAME "${TARGET_NAME}")

    add_executable(${TARGET_NAME} ${CPP_FILE})

    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/files
            ${CMAKE_BINARY_DIR}/files
            COMMENT "Copying files directory to build folder"
    )

    message(STATUS "Created: ${TARGET_NAME} <- ${CPP_FILE}")
endforeach()
