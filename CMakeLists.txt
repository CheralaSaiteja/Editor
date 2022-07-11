cmake_minimum_required(VERSION 3.18.0)
project(Editor VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.7
)
FetchContent_MakeAvailable(glfw)
include(FetchContent)
FetchContent_Declare(
    Scripting
    GIT_REPOSITORY https://github.com/CheralaSaiteja/Scripting.git
)
FetchContent_MakeAvailable(Scripting)
include(FetchContent)
FetchContent_Declare(
    Core
    GIT_REPOSITORY https://github.com/CheralaSaiteja/Core.git
)
FetchContent_MakeAvailable(Core)
file(GLOB_RECURSE SRC src/*.cpp) 
add_executable(Editor main.cpp ${SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw Core Scripting)