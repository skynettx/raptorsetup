cmake_minimum_required(VERSION 3.10)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(CMAKE_CXX_FLAGS "-O3")
SET(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-O3")
SET(CMAKE_C_STANDARD 11)

if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

project(raptorsetup)

if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    if(MSVC)
        set(SDL2_DIR "include/SDL2-devel-2.28.2-VC/SDL2-2.28.2/cmake")
    else()
        set(SDL2_DIR "include/SDL2-devel-2.28.2-mingw/SDL2-2.28.2/cmake")
    endif()
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
else()
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
endif()

include_directories(./include/textscreen/include/)

add_subdirectory(./include/textscreen/include)

add_executable(${CMAKE_PROJECT_NAME}
    src/input.c
    src/main.c
    src/music.c
    src/prefapi.c
    src/sound.c
    src/txt_joyinput.c
    src/txt_keyinput.c
    src/txt_mouseinput.c
)

if(WIN32)
    target_sources(raptorsetup PRIVATE rsrc/resource.rc)
endif()
target_link_libraries(raptorsetup
    textscreen
    SDL2::SDL2main
    SDL2::SDL2
    )
if(${CMAKE_BUILD_TYPE} MATCHES "RelWithDebInfo" OR ${CMAKE_BUILD_TYPE} MATCHES "Release")
    if(MSVC)
        target_link_options(raptorsetup PRIVATE /subsystem:windows /ENTRY:mainCRTStartup)
    elseif(WIN32)
        target_link_options(raptorsetup PRIVATE -mwindows)
    endif()
elseif(WIN32 AND NOT MSVC)
    target_link_options(raptorsetup PRIVATE -mconsole)
endif()

