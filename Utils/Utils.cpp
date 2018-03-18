//
//  Utils.cpp
//  
//
//  Created by Роман Климовицкий on 17.03.2018.
//

#include <cmath>
#include "Utils/Utils.hpp"


std::mt19937 Utils::generator;

const double Utils::minDamageMultiplier_ = 0.95;
const double Utils::maxDamageMultiplier_ = 1.05;
const double Utils::armorMultiplier_ = 0.06;

const int Utils::startWorkers_ = 5;
const int Utils::startTownHalls_ = 1;
const int Utils::xStartPositionShift_ = 20;
const int Utils::yStartPositionShift_ = 20;

bool Utils::random_ = false;

void Utils::initRandom() {
    if(!random_) {
        generator.seed(time(0));
        random_ = true;
    }
}

int Utils::getRandom(int from, int to) { return generator() %
    (to - from + 1) + from; }

int Utils::calculateDamage(int damage, int armor) {
    if(damage <= 0)
        return 0;
    int minDamage = floor(damage * minDamageMultiplier_);
    int maxDamage = floor(damage * maxDamageMultiplier_);
    int clearDamage = getRandom(minDamage, maxDamage);
    double reductionK = 1 - (armor * armorMultiplier_) /
    (1 + abs(armor) * armorMultiplier_);
    int realDamage = floor(clearDamage * reductionK);
    return realDamage;
}

double Utils::calculateDistance(std::pair<int, int> first,
                                std::pair<int, int> second) {
    return sqrt(pow(first.first - second.second, 2) +
                pow(first.second - second.second, 2));
}
