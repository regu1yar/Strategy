//
//  Utils.cpp
//  
//
//  Created by Роман Климовицкий on 17.03.2018.
//

#include <cmath>
#include "Utils/Utils.hpp"


std::mt19937 Utils::generator;
bool Utils::random_ = false;


void Utils::initRandom() {
    if(!random_) {
        generator.seed(time(0));
        random_ = true;
    }
}

int Utils::getRandom(int from, int to) { return generator() % (to - from + 1) + from; }


