cmake_minimum_required(VERSION 3.10)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(CMAKE_CXX_FLAGS "-O3")
SET(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-O3")
SET(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

project(raptorsetup)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(./src/)
include_directories(./include/textscreen/include/)

add_subdirectory(./include/textscreen/include)
add_executable(${CMAKE_PROJECT_NAME}
    src/input.c
    src/main.c
    src/music.c
    src/prefapi.c
    src/sound.c
    src/help.c
    src/txt_joyinput.c
    src/txt_keyinput.c
    src/txt_mouseinput.c
)

    target_link_libraries(raptorsetup
        textscreen
        SDL2::SDL2
        SDL2::SDL2main
        )

