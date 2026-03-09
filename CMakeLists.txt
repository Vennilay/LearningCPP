cmake_minimum_required(VERSION 3.20)
project(LearningCPP CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE ALL_CPP CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/Semester_1/*.cpp"
        "${CMAKE_SOURCE_DIR}/Semester_2/*.cpp"
)

file(GLOB_RECURSE ALL_HEADERS CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/Semester_1/*.h"
        "${CMAKE_SOURCE_DIR}/Semester_1/*.hpp"
        "${CMAKE_SOURCE_DIR}/Semester_2/*.h"
        "${CMAKE_SOURCE_DIR}/Semester_2/*.hpp"
)

foreach(SOURCE_FILE ${ALL_CPP})
    file(RELATIVE_PATH REL_PATH "${CMAKE_SOURCE_DIR}" "${SOURCE_FILE}")

    string(REPLACE "/" "_" TARGET_NAME "${REL_PATH}")
    string(REPLACE ".cpp" "" TARGET_NAME "${TARGET_NAME}")

    add_executable(${TARGET_NAME})
    target_sources(${TARGET_NAME} PRIVATE "${SOURCE_FILE}")

    foreach(HEADER_FILE ${ALL_HEADERS})
        get_filename_component(HEADER_DIR "${HEADER_FILE}" DIRECTORY)
        target_include_directories(${TARGET_NAME} PRIVATE "${HEADER_DIR}")
    endforeach()

    target_include_directories(${TARGET_NAME} PRIVATE
            "${CMAKE_SOURCE_DIR}/Semester_1"
            "${CMAKE_SOURCE_DIR}/Semester_2"
    )

    get_filename_component(SOURCE_DIR_ABS "${SOURCE_FILE}" DIRECTORY)

    set(FILES_DIR_TO_COPY "")

    if(EXISTS "${SOURCE_DIR_ABS}/files")
        set(FILES_DIR_TO_COPY "${SOURCE_DIR_ABS}/files")
    elseif(EXISTS "${SOURCE_DIR_ABS}/../files")
        get_filename_component(PARENT_DIR "${SOURCE_DIR_ABS}/.." ABSOLUTE)
        set(FILES_DIR_TO_COPY "${PARENT_DIR}/files")
    endif()

    if(NOT FILES_DIR_TO_COPY STREQUAL "")
        add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${TARGET_NAME}>/files"
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${FILES_DIR_TO_COPY}"
                "$<TARGET_FILE_DIR:${TARGET_NAME}>/files"
        )
    endif()
endforeach()
