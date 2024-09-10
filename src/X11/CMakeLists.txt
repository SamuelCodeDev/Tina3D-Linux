find_package(X11 REQUIRED)
set(LIBRARY ${X11_LIBRARIES})
set(SOURCE_FILES Window.cpp
    Input.cpp
    ../Error.cpp
    X11Error.cpp)

add_library(windowLibrary STATIC ${SOURCE_FILES})
target_include_directories(windowLibrary PRIVATE ../include)
target_include_directories(windowLibrary PUBLIC include)
target_link_libraries(windowLibrary PRIVATE ${LIBRARY})

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_compile_definitions(windowLibrary PUBLIC _DEBUG)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    target_compile_definitions(windowLibrary PUBLIC NDEBUG)
endif()