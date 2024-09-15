cmake_minimum_required(VERSION 3.5)
project(Tina3D LANGUAGES CXX)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif ()

option (ENABLE_EXAMPLES "Enable examples" ON)

if(UNIX AND NOT APPLE)
    option (ENABLE_X11 "Enable X11 support." ON)
    option (ENABLE_VULKAN "Enable Vulkan support." ON)
endif()

add_subdirectory(src)

set(TINA_LIBRARIES window graphics)

if(ENABLE_EXAMPLES)
    add_subdirectory(examples)
endif()