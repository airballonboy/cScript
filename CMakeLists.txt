cmake_minimum_required(VERSION 3.28)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

project(cScript)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

add_executable("${CMAKE_PROJECT_NAME}" ${MY_SOURCES})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")

target_include_directories("${CMAKE_PROJECT_NAME}"
						   PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)

#create sim link for compile_commands.json
execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
)
