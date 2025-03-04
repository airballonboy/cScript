cmake_minimum_required(VERSION 3.28)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

project(cScript)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/cScript.c"
)

add_executable("${CMAKE_PROJECT_NAME}" ${MY_SOURCES})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")

#create sim link for compile_commands.json
execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
)
