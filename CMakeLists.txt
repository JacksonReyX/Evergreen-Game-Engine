# raylib 6.0's own CMakeLists requires 3.25, so say so up front
cmake_minimum_required(VERSION 3.25)

project(Evergreen_Engine LANGUAGES C CXX)

# macOS: raylib's bundled GLFW has Objective-C sources (cocoa_*.m) but never
# turns the language on itself, so it has to be enabled here, at the top level.
# Without it: "Missing variable is: CMAKE_OBJC_COMPILE_OBJECT".
if(APPLE)
    enable_language(OBJC)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Everything lives one folder down
set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

include(FetchContent)

# CMake 4 refuses projects that ask for a minimum below 3.5, and the freetype
# SFML downloads still asks for 2.8.12. This lets fetched dependencies
# configure anyway, without editing anything under build/_deps.
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

###############################################################################
# SFML 3
#
# Use an installed copy when there is one. Most Linux distributions still
# package SFML 2.6, whose API differs, so the fallback fetches and builds
# SFML 3.0.0 as part of this project. That build is slow the first time only.
###############################################################################

find_package(SFML 3 COMPONENTS Graphics Window System QUIET)

if(NOT SFML_FOUND)
    message(STATUS "No SFML 3 installation found: fetching and building SFML 3.0.0")

    set(SFML_BUILD_AUDIO    OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_NETWORK  OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_DOC      OFF CACHE BOOL "" FORCE)

    FetchContent_Declare(SFML
            GIT_REPOSITORY https://github.com/SFML/SFML.git
            GIT_TAG        3.0.0
            GIT_SHALLOW    TRUE)

    FetchContent_MakeAvailable(SFML)
endif()

###############################################################################
# Lua 5.4
#
# sol2 (header-only, vendored under libs/sol) needs a real Lua to link against.
# libs/lua holds headers and a Windows static library, which is no use on Linux
# or macOS, so prefer an installed Lua and otherwise build one from source.
###############################################################################

find_package(Lua 5.4 QUIET)

if(LUA_FOUND)
    message(STATUS "Using installed Lua: ${LUA_LIBRARIES}")

    add_library(lua_engine INTERFACE)
    target_include_directories(lua_engine INTERFACE ${LUA_INCLUDE_DIR})
    target_link_libraries(lua_engine INTERFACE ${LUA_LIBRARIES})
else()
    message(STATUS "No Lua 5.4 installation found: fetching and building Lua 5.4.6")

    FetchContent_Declare(lua
            GIT_REPOSITORY https://github.com/lua/lua.git
            GIT_TAG        v5.4.6
            GIT_SHALLOW    TRUE)

    FetchContent_MakeAvailable(lua)

    # Lua ships no build system of its own: compile every core and library
    # source, minus the two standalone programs (the interpreter and luac).
    file(GLOB LUA_SOURCES ${lua_SOURCE_DIR}/*.c)
    list(FILTER LUA_SOURCES EXCLUDE REGEX "(lua|luac|onelua)\\.c$")

    add_library(lua_engine STATIC ${LUA_SOURCES})
    target_include_directories(lua_engine PUBLIC ${lua_SOURCE_DIR})

    if(UNIX)
        # Lets Lua use dlopen and the POSIX bits; also what sol2 expects
        target_compile_definitions(lua_engine PRIVATE LUA_USE_POSIX)
        target_link_libraries(lua_engine PUBLIC ${CMAKE_DL_LIBS} m)
    endif()

    # The git mirror has no lua.hpp (it only ships with the lua.org tarball),
    # and sol2 includes it, so generate one next to the build.
    set(LUA_HPP_DIR ${CMAKE_BINARY_DIR}/lua-hpp)
    file(WRITE ${LUA_HPP_DIR}/lua.hpp
            "extern \"C\" {\n#include \"lua.h\"\n#include \"lualib.h\"\n#include \"lauxlib.h\"\n}\n")
    target_include_directories(lua_engine PUBLIC ${LUA_HPP_DIR})
endif()

###############################################################################
# raylib 6.0
#
# Fetched and built as a static library next to SFML. raylib is C, but its
# headers have extern "C" guards, so #include "raylib.h" works from C++.
#
# Linux also needs: sudo apt install libxinerama-dev
# (raylib's bundled GLFW requires it; SFML does not, so the README list lacks it)
###############################################################################

set(RAYLIB_VERSION 6.0)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        ${RAYLIB_VERSION}
        GIT_SHALLOW    TRUE)

FetchContent_MakeAvailable(raylib)

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    if (NOT DEFINED RAYLIB_CPP_VERSION)
        set(RAYLIB_CPP_VERSION v6.0.0)
    endif()
    include(FetchContent)
    FetchContent_Declare(
            raylib_cpp
            GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
            GIT_TAG ${RAYLIB_CPP_VERSION}
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

# SFML and raylib each compile their own copy of stb_image / stb_image_write
# with public symbols, so linking both fails with
#   multiple definition of `stbi_image_free' (LNK2005 on MSVC).
# Only raylib's rtextures.c calls stb, so make raylib's copy file-private.
target_compile_definitions(raylib PRIVATE STB_IMAGE_STATIC STB_IMAGE_WRITE_STATIC)


###############################################################################
# The game
#
# The target is called "engine" rather than "game" so its output cannot clash
# with a source folder on a case-insensitive filesystem.
#
# ImGui and ImGui-SFML are vendored under libs/imgui, and sol2 under libs/sol,
# so they compile straight into the target rather than being found on the
# system.
###############################################################################

add_executable(engine
        ${SRC}/main.cpp
        ${SRC}/Game/game.cpp
        ${SRC}/Game/LevelLoader.cpp
        ${SRC}/ECS/ECS.cpp
        ${SRC}/Logger/Logger.cpp
        ${SRC}/AssetStore/AssetStore.cpp

        ${SRC}/libs/imgui/imgui.cpp
        ${SRC}/libs/imgui/imgui_draw.cpp
        ${SRC}/libs/imgui/imgui_tables.cpp
        ${SRC}/libs/imgui/imgui_widgets.cpp
        ${SRC}/libs/imgui/imgui-SFML.cpp
        src/Components/tileComponent.h
        src/Systems/playerMovementSystem.h
        src/Components/MoveableComponent.h
        src/Systems/CameraSystem.h
        src/Systems/collisionResolutionSystem.h
        src/Systems/DashSystem.h
        src/Events/PlayerMoveEvent.h
)

target_include_directories(engine PRIVATE
        ${SRC}
        ${SRC}/libs/imgui
        ${SRC}/libs/sol)

# ImGui-SFML needs its own ImGui config; the Visual Studio project sets this
# through project properties
target_compile_definitions(engine PRIVATE IMGUI_USER_CONFIG="imconfig-SFML.h")

target_link_libraries(engine PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
        lua_engine
        raylib
        raylib_cpp
)

###############################################################################
# Running
#
# Assets and imgui.ini are resolved relative to the working directory, so the
# binary is placed in the source folder and Visual Studio is told to debug
# from there.
###############################################################################

set_target_properties(engine PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${SRC}
        VS_DEBUGGER_WORKING_DIRECTORY ${SRC})

# Windows: put the SFML DLLs next to the executable when SFML was built here
if(WIN32 AND NOT SFML_FOUND)
    add_custom_command(TARGET engine POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:engine> $<TARGET_RUNTIME_DLLS:engine>
            COMMAND_EXPAND_LISTS)
endif()