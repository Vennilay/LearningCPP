cmake_minimum_required(VERSION 3.20)
project(LearningCPP)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE ALL_CPP_FILES
        "homework/*.cpp"
        "practise/*.cpp"
        "tests/*.cpp"
)

foreach(CPP_FILE ${ALL_CPP_FILES})
    file(RELATIVE_PATH REL_PATH ${CMAKE_SOURCE_DIR} ${CPP_FILE})

    string(REGEX REPLACE "[/\\\\]" "_" TARGET_NAME "${REL_PATH}")
    string(REPLACE ".cpp" "" TARGET_NAME "${TARGET_NAME}")

    add_executable(${TARGET_NAME} ${CPP_FILE})

    message(STATUS "Created: ${TARGET_NAME} <- ${CPP_FILE}")
endforeach()
