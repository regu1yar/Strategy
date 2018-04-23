cmake_minimum_required(VERSION 2.6)
project(MyStrategy)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if(DEBUG)
	set(CMAKE_BUILD_TYPE Debug)
else()
	set(CMAKE_BUILD_TYPE Release)
endif()

if(WITH_TEST)
	find_package(GTest REQUIRED)
	include_directories(${GTEST_INCLUDE_DIRS})
endif()

include_directories(${CMAKE_SOURCE_DIR})

file(GLOB UNITS_SOURCE Units/*.hpp Units/*.cpp)
file(GLOB PLAYER_SOURCE Player/*.hpp Player/*.cpp)
file(GLOB UTILS_SOURCE Utils/*.hpp Utils/*.cpp)
file(GLOB ARMY_SOURCE Army/*.hpp Army/*.cpp)
file(GLOB MAP_SOURCE Map/*.hpp Map/*.cpp)
file(GLOB GAME_PROCESS_SOURCE Game_Process/*.hpp Game_Process/*.cpp)

add_library(MyStrategyLib ${UNITS_SOURCE} ${PLAYER_SOURCE} ${UTILS_SOURCE}
		${ARMY_SOURCE} ${MAP_SOURCE} ${GAME_PROCESS_SOURCE})
if(WITH_TEST)
	file(GLOB TESTS Test/*.hpp)
	add_executable(MyStrategy main.cpp ${TESTS})
	target_link_libraries(MyStrategy MyStrategyLib ${GTEST_LIBRARIES} pthread)
endif()
