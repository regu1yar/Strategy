cmake_minimum_required(VERSION 2.6)
project(MyStrategy)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if(DEBUG="ON")
	set(CMAKE_BUILD_TYPE Debug)
else()
	set(CMAKE_BUILD_TYPE Release)
endif()

if(WITH_TEST)
	find_package(GTest REQUIRED)
	include_directories(${GTEST_INCLUDE_DIRS})
endif()

include_directories(${CMAKE_SOURCE_DIR})

set(UNITS_SOURCE Units/Unit.hpp Units/Unit.cpp Units/Building.hpp Units/Building.cpp Units/Creature.hpp Units/Creature.cpp Units/UnitFactory.hpp Units/OrcUnitFactory.hpp Units/HumanUnitFactory.hpp Units/HumanUnits.hpp Units/HumanUnits.cpp Units/OrcUnits.hpp Units/OrcUnits.cpp)

set(PLAYER_SOURCE Player/Player.hpp Player/Player.cpp Player/PlayerDirector.hpp Player/PlayerDirector.cpp)

set(UTILS_SOURCE Utils/Utils.hpp Utils/Utils.cpp)

add_library(MyStrategyLib ${UNITS_SOURCE} ${PLAYER_SOURCE} ${UTILS_SOURCE})
if(WITH_TEST)
	set(TESTS Test/PlayerTest.hpp Test/UnitsTest.hpp)
	add_executable(MyStrategy main.cpp ${TESTS})
	target_link_libraries(MyStrategy MyStrategyLib ${GTEST_LIBRARIES} pthread)
endif()
