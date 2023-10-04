cmake_minimum_required(VERSION 3.17)

cmake_policy(VERSION 3.17)

set(CMAKE_BUILD_TYPE Release)
set(EXEC browser)

project(${EXEC} VERSION 1.0
        DESCRIPTION "Browser for shell"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(SRCS
        src/main.cpp
        src/shellBrowser.cpp
        src/prompt/Prompt.cpp
        src/error/Error.cpp
        )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(${EXEC} ${SRCS})

target_include_directories(${EXEC} PUBLIC includes)

set_target_properties(${EXEC} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})