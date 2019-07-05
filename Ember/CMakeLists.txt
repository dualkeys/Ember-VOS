cmake_minimum_required(VERSION 3.14)

project(Ember)

set(project_headers
    src/include/console.hpp)

set(project_sources
    src/console.cpp
    src/Source.cpp)

add_executable(${PROJECT_NAME} ${project_headers} ${project_sources})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        src/include
)

# now add an executable per "command"
# create a list of commands
set(command_executables
    Commands/cd.cpp)

foreach(cmd ${command_executables})
    # get the file name without an extension or parent directory
    get_filename_component(file_name ${cmd} NAME_WLE)
    add_executable(${file_name} ${cmd})
endforeach()
