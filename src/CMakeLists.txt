if(ENABLE_X11)
    add_subdirectory(X11)
    set(SOURCE_FILES Game.cpp X11/Engine.cpp)
endif()

#the graphics library
#add_subdirectory(graphics)

set(LIBRARYS windowLibrary)

add_library(window ${SOURCE_FILES})
target_include_directories(window PUBLIC include)
target_link_libraries(window PUBLIC ${LIBRARYS})