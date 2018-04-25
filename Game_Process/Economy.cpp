//
// Created by Роман Климовицкий on 21/04/2018.
//

#include "Economy.hpp"


const int Economy::startGold = 500;

Economy::Economy(int gold) : gold_(gold) { }

int Economy::getGold() const { return gold_; }

bool Economy::expense(size_t amount) {
    if (gold_ >= amount) {
        gold_ -= amount;
        return true;
    } else
        return false;
}

void Economy::income(size_t amount) { gold_ += amount; }