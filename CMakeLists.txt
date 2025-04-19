cmake_minimum_required(VERSION 3.15)
project(StickyStick)

set(CMAKE_CXX_STANDARD 17)

# Configura compilatori
if(DEFINED ENV{MINGW_ROOT})
    set(CMAKE_C_COMPILER "$ENV{MINGW_ROOT}/bin/gcc.exe")
    set(CMAKE_CXX_COMPILER "$ENV{MINGW_ROOT}/bin/g++.exe")
endif()

# Configura SFML
if(DEFINED ENV{SFML_ROOT})
    set(SFML_DIR "$ENV{SFML_ROOT}/lib/cmake/SFML")
endif()

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SFML_INCLUDE_DIR}
)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system
)

# Copia automatica delle DLL
if(WIN32 AND SFML_ROOT)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            "${SFML_ROOT}/bin/sfml-graphics-3.dll"
            "${SFML_ROOT}/bin/sfml-window-3.dll"
            "${SFML_ROOT}/bin/sfml-system-3.dll"
        DESTINATION
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()