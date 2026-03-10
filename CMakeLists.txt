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

set(MAIN_SOURCES "")
foreach(SRC IN LISTS ALL_CPP)
    file(STRINGS "${SRC}" MAIN_MATCH REGEX "^[ \t]*int[ \t\r\n]+main[ \t\r\n]*\\(")
    if(MAIN_MATCH)
        list(APPEND MAIN_SOURCES "${SRC}")
    endif()
endforeach()

foreach(MAIN_SRC IN LISTS MAIN_SOURCES)
    file(RELATIVE_PATH REL_PATH "${CMAKE_SOURCE_DIR}" "${MAIN_SRC}")
    string(REPLACE "/" "_" TARGET_NAME "${REL_PATH}")
    string(REPLACE ".cpp" "" TARGET_NAME "${TARGET_NAME}")

    get_filename_component(SRC_DIR "${MAIN_SRC}" DIRECTORY)

    file(GLOB LOCAL_CPP CONFIGURE_DEPENDS "${SRC_DIR}/*.cpp")
    set(TARGET_CPP "${MAIN_SRC}")

    foreach(CPP IN LISTS LOCAL_CPP)
        if(NOT CPP STREQUAL MAIN_SRC)
            file(STRINGS "${CPP}" OTHER_MAIN REGEX "^[ \t]*int[ \t\r\n]+main[ \t\r\n]*\\(")
            if(NOT OTHER_MAIN)
                list(APPEND TARGET_CPP "${CPP}")
            endif()
        endif()
    endforeach()

    add_executable("${TARGET_NAME}" ${TARGET_CPP})

    target_include_directories("${TARGET_NAME}" PRIVATE
            "${SRC_DIR}"
            "${CMAKE_SOURCE_DIR}/Semester_1"
            "${CMAKE_SOURCE_DIR}/Semester_2"
    )

    foreach(HEADER_FILE IN LISTS ALL_HEADERS)
        get_filename_component(HEADER_DIR "${HEADER_FILE}" DIRECTORY)
        target_include_directories("${TARGET_NAME}" PRIVATE "${HEADER_DIR}")
    endforeach()

    set(FILES_DIR_TO_COPY "")
    if(EXISTS "${SRC_DIR}/files")
        set(FILES_DIR_TO_COPY "${SRC_DIR}/files")
    elseif(EXISTS "${SRC_DIR}/../files")
        get_filename_component(PARENT_DIR "${SRC_DIR}/.." ABSOLUTE)
        set(FILES_DIR_TO_COPY "${PARENT_DIR}/files")
    endif()

    if(NOT FILES_DIR_TO_COPY STREQUAL "")
        add_custom_command(TARGET "${TARGET_NAME}" POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${TARGET_NAME}>/files"
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${FILES_DIR_TO_COPY}"
                "$<TARGET_FILE_DIR:${TARGET_NAME}>/files"
        )
    endif()
endforeach()
