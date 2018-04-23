//
//  main.cpp
//  
//
//  Created by Роман Климовицкий on 18.03.2018.
//

#include "Test/UnitsTest.hpp"
#include "Test/PlayerTest.hpp"
#include "Test/ArmyTest.hpp"


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
