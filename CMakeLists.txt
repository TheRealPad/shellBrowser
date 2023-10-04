cmake_minimum_required(VERSION 3.17)

cmake_policy(VERSION 3.17)

set(CMAKE_BUILD_TYPE Release)
set(EXEC browser)
set(TEST_EXEC unit_test)

project(${EXEC} VERSION 1.0
        DESCRIPTION "Browser for shell"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(SRCS
        src/shellBrowser.cpp
        src/prompt/Prompt.cpp
        src/error/Error.cpp
        )

set(MAIN
        src/main.cpp)

set(TEST_SRCS
        tests/prompt/prompt.test.cpp
        )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
add_executable(${EXEC} ${MAIN} ${SRCS})
target_include_directories(${EXEC} PUBLIC includes)
set_target_properties(${EXEC} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(${TEST_EXEC} ${TEST_SRCS})
target_include_directories(${TEST_EXEC} PUBLIC includes)
add_test(NAME ${TEST_EXEC}
         COMMAND ${TEST_EXEC})