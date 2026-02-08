cmake_minimum_required(VERSION 3.20)
project(LearningCPP CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
        RELATIVE "${CMAKE_SOURCE_DIR}"
        "Semester_1/*.cpp"
        "Semester_2/*.cpp"
)

foreach(SOURCE_FILE ${SOURCES})
    string(REPLACE "/" "_" TARGET_NAME "${SOURCE_FILE}")
    string(REPLACE ".cpp" "" TARGET_NAME "${TARGET_NAME}")

    add_executable(${TARGET_NAME} "${SOURCE_FILE}")

    get_filename_component(SOURCE_DIR_ABS "${CMAKE_SOURCE_DIR}/${SOURCE_FILE}" DIRECTORY)

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
                COMMENT "Found 'files' at ${FILES_DIR_TO_COPY}. Copying..."
        )
    endif()

endforeach()
