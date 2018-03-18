//
//  Creature.cpp
//  
//
//  Created by Роман Климовицкий on 16.03.2018.
//

#include "Units/Creature.hpp"
#include "Units/UnitFactory.hpp"
#include "Units/Building.hpp"
#include "Utils/Utils.hpp"


Creature::Creature(size_t id, std::string name, size_t xSize, size_t ySize,
                   int x, int y, int health, int armor, int damage, double range) :
Unit(id, name, xSize, ySize, x, y, health, armor), damage_(damage), range_(range) { }

int Creature::getDamage() const { return damage_; }

double Creature::getRange() const { return range_; }

void Creature::update() {
    Unit::update();
    damage_ = std::max(damage_, 0);
}

void Creature::attack(std::shared_ptr<Unit> target) const {
    try {
        if(target == nullptr)
            throw 0;
        try {
            if(Utils::calculateDistance(getPosition(), target->getPosition()) < range_)
                throw 1;
        } catch(int a) {
            std::cout << name_ << " can't attack this unit: it is too far." << std::endl;
            return;
        }
        int damage = Utils::calculateDamage(damage_, target->getArmor());
        std::cout << name_ << " attacks " << target->getName() << " and deals " << damage
        << " damage." << std::endl;
        target->takeDamage(damage);
    } catch(int a) {
        std::cout << name_ << " can't attack this unit: it doesn't exist." << std::endl;
    }
}

void Creature::moveTo(int x, int y) {
    std::cout << name_ << " moves to the (" << x << ", " << y << ")." << std::endl;
    x_ = x;
    y_ = y;
}

void Creature::moveBy(int x, int y) {
    moveTo(x_ + x, y_ + y);
}


Worker::Worker(size_t id, std::string name, size_t xSize, size_t ySize,
               int x, int y, int health, int armor, int damage, double range,
               std::shared_ptr<UnitFactory> buildingFactory) :
Creature(id, name, xSize, ySize, x, y, health, armor, damage, range),
buildingFactory_(buildingFactory) { }

std::shared_ptr<TownHall> Worker::buildTownHall() const {
    std::shared_ptr<TownHall> townHall = buildingFactory_->getTownHall(x_ + xSize_, y_ + ySize_);
    std::cout << name_ << " build a " << townHall->getName() << std::endl;
    return townHall;
}

std::shared_ptr<TownHall> Worker::buildTownHall(int x, int y) {
    moveTo(x - xSize_, y - ySize_);
    return buildTownHall();
}

std::shared_ptr<Barracks> Worker::buildBarracks() const {
    std::shared_ptr<Barracks> barracks = buildingFactory_->getBarracks(x_ + xSize_, y_ + ySize_);
    std::cout << name_ << " build a " << barracks->getName() << std::endl;
    return barracks;
}

std::shared_ptr<Barracks> Worker::buildBarracks(int x, int y) {
    moveTo(x - xSize_, y - ySize_);
    return buildBarracks();
}


Warrior::Warrior(size_t id, std::string name, size_t xSize, size_t ySize,
                 int x, int y, int health, int armor, int damage, double range) :
Creature(id, name, xSize, ySize, x, y, health, armor, damage, range) { }


Archer::Archer(size_t id, std::string name, size_t xSize, size_t ySize,
                int x, int y, int health, int armor, int damage, double range) :
Creature(id, name, xSize, ySize, x, y, health, armor, damage, range) { }


Healer::Healer(size_t id, std::string name, size_t xSize, size_t ySize,
               int x, int y, int health, int armor, int damage, double range,
               size_t heal, double healRange) :
Creature(id, name, xSize, ySize, x, y, health, armor, damage, range),
heal_(heal), healRange_(healRange) { }

void Healer::heal(std::shared_ptr<Unit> target) {
    try {
        if(target == nullptr)
            throw 0;
        try {
            if(Utils::calculateDistance(getPosition(), target->getPosition()) < range_)
                throw 1;
        } catch(int a) {
            std::cout << name_ << " can't heal this unit: it is too far." << std::endl;
            return;
        }
        std::cout << name_ << " heals " << target->getName() << " for " << heal_
        << " points." << std::endl;
        target->takeHeal(heal_);
    } catch(int a) {
        std::cout << name_ << " can't heal this unit: it doesn't exist." << std::endl;
    }
}
