cmake_minimum_required (VERSION 3.10)

# Define the project
project(veca-nota)

# Define SDL2
set(SDL2_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/libs/SDL2/x86_64-w64-mingw32/include")
find_package(SDL2)

if ("${CMAKE_SYSTEM_NAME}" MATCHES "Windows")
	if (${CMAKE_SIZEOF_VOID_P} MATCHES 8) # 64-bit
		set(SDL2_LIBRARIES "-L${CMAKE_SOURCE_DIR}/libs/SDL2/x86_64-w64-mingw32/lib -lsdl2")
	elseif (${CMAKE_SIZEOF_VOID_P} EQUAL 4) # 32-bit
		set(SDL2_LIBRARIES "-L${CMAKE_SOURCE_DIR}/libs/SDL2/i686-w64-mingw32/lib -lsdl2")
	else ()
		message(STATUS "Target build arch is unknown.")
	endif ()
endif()

# Add definition for the veca-nota binary
add_executable(veca-nota
	src/renderer.cpp
	src/string.cpp
	src/main.cpp
)

# Add SDL2
target_include_directories(veca-nota PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(veca-nota ${SDL2_LIBRARIES})
