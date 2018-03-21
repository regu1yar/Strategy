//
//  Unit.cpp
//  
//
//  Created by Роман Климовицкий on 16.03.2018.
//

#include "Units/Unit.hpp"


size_t Unit::counter_ = 0;

Unit::Unit(size_t id, std::string name, size_t xSize, size_t ySize, int x, int y, int maxHealth, int health, int armor) :
        uniqueId_(counter_), id_(id), name_(name), xSize_(xSize), ySize_(ySize), x_(x), y_(y),
        maxHealth_(maxHealth), health_(health), armor_(armor) { ++counter_; }

size_t Unit::getUniqueId() const { return uniqueId_; }

size_t Unit::getId() const { return id_; }

std::string Unit::getName() const { return name_; }

std::pair<size_t, size_t> Unit::getSize() const { return {xSize_, ySize_}; }

std::pair<int, int> Unit::getPosition() const { return {x_, y_}; }

int Unit::getMaxHealth() const { return maxHealth_; }

int Unit::getHealth() const { return health_; }

int Unit::getArmor() const { return armor_; }

void Unit::takeDamage(int damage) {
    health_ -= damage;
    update();
}

void Unit::takeHeal(int heal) {
    health_ += heal;
    update();
}

void Unit::update() { health_ = std::min(std::max(health_, 0), maxHealth_); }
