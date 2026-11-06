cmake_minimum_required (VERSION 3.11)

set(PROJECT_NAME "Striker")
project (${PROJECT_NAME})

set (SOURCES 
"code/main.cpp" 
"code/game_control.cpp"
"code/gamemode.cpp"
"code/object.cpp" 
"code/player.cpp" 
"code/asteroid.cpp")
set (HEADERS 
"code/game_control.h"
"code/gamemode.h"
"code/object.h"
"code/player.h" 
"code/asteroid.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/data
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/data
)

target_include_directories(${PROJECT_NAME} PUBLIC
    code
    data
)