cmake_minimum_required(VERSION 3.10)
project(VulkanExperiment)

set(CMAKE_CXX_STANDARD 23)

# Find Vulkan
find_package(Vulkan REQUIRED)

# Add GLFW
add_subdirectory(lib/glfw-3.4)

# Add GLM (Manual Include)
find_package(glm)

# Include source files and headers
include_directories(${CMAKE_SOURCE_DIR})

set(SOURCES
    src/main.cpp
    include/window/window.cpp
    include/app/app.cpp
    include/pipeline/pipeline.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} glfw Vulkan::Vulkan)

