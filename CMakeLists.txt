cmake_minimum_required(VERSION 3.17)

cmake_policy(VERSION 3.17)

set(CMAKE_BUILD_TYPE Release)
set(EXEC shellBrowser)
set(TEST_EXEC unit_test)

project(${EXEC} VERSION 1.0
        DESCRIPTION "Browser for shell"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

set(SRCS
        src/shellBrowser.cpp
        src/prompt/Prompt.cpp
        src/prompt/NcursePrompt.cpp
        src/browser/Browser.cpp
        src/error/Error.cpp
        src/utils/getRequest.cpp
        src/utils/formatUrl.cpp
)

set(MAIN
        src/main.cpp
)

set(TEST_SRCS
        tests/test.cpp
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
add_executable(${EXEC} ${MAIN} ${SRCS})
target_include_directories(${EXEC} PUBLIC includes)
target_link_libraries(${EXEC} PRIVATE curl)
target_link_libraries(${EXEC} PRIVATE -lncurses)
set_target_properties(${EXEC} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(${TEST_EXEC} ${TEST_SRCS} ${SRCS})
target_include_directories(${TEST_EXEC} PUBLIC includes)
target_link_libraries(${TEST_EXEC} PRIVATE curl)
target_link_libraries(${TEST_EXEC} PRIVATE -lncurses)
add_test(NAME ${TEST_EXEC}
        COMMAND ${TEST_EXEC})