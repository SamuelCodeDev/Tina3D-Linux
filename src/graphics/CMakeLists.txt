if(ENABLE_VULKAN)
    find_package(Vulkan REQUIRED)
    set(HEADER_FILES vulkan/include ${Vulkan_INCLUDE_DIRS})
    set(SOURCE_FILES vulkan/Graphics.cpp
        vulkan/VulkanError.cpp)
    set(LIBRARY Vulkan::Vulkan)
endif()

add_library(graphics STATIC ${SOURCE_FILES})
target_include_directories(graphics PRIVATE ../include)
target_include_directories(graphics PUBLIC ${HEADER_FILES})
target_link_libraries(graphics PRIVATE ${LIBRARY} windowLibrary)

if(ENABLE_X11)
    target_compile_definitions(graphics PRIVATE VK_USE_PLATFORM_XLIB_KHR)
endif()