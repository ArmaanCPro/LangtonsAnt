cmake_minimum_required(VERSION 3.28)

project (main CXX)

# platform
if (WIN32 OR MINGW)
    set(PLATFORM_DEFINITIONS ME_WINDOWS)
elseif (APPLE)
    set(PLATFORM_DEFINITIONS ME_OSX)
elseif (UNIX AND NOT APPLE)
    set(PLATFORM_DEFINITIONS ME_LINUX)
endif ()
add_compile_definitions(${PLATFORM_DEFINITIONS})

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Set include directories
target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master # Or a specific version tag like 5.0
)
FetchContent_MakeAvailable(raylib)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
