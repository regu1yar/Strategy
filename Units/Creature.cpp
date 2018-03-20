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


const double Creature::minDamageMultiplier_ = 0.95;
const double Creature::maxDamageMultiplier_ = 1.05;
const double Creature::armorMultiplier_ = 0.06;

int Creature::calculateDamage(int damage, int armor) {
    if(damage <= 0)
        return 0;
    int minDamage = floor(damage * minDamageMultiplier_);
    int maxDamage = floor(damage * maxDamageMultiplier_);
    int clearDamage = Utils::getRandom(minDamage, maxDamage);
    double reductionK = 1 - (armor * armorMultiplier_) /
                            (1 + abs(armor) * armorMultiplier_);
    int realDamage = floor(clearDamage * reductionK);
    return realDamage;
}

double Creature::calculateDistance(std::pair<int, int> first,
                                std::pair<int, int> second) {
    return sqrt(pow(first.first - second.second, 2) +
                pow(first.second - second.second, 2));
}


Creature::Creature(size_t id, std::string name, size_t xSize, size_t ySize,
                   int x, int y, int health, int armor, int damage, double range) :
        Unit(id, name, xSize, ySize, x, y, health, armor), damage_(damage), range_(range) { }

int Creature::getDamage() const { return damage_; }

double Creature::getRange() const { return range_; }

void Creature::update() {
    Unit::update();
    range_ = std::max(range_, 0.0);
    damage_ = std::max(damage_, 0);
}

void Creature::attack(std::shared_ptr<Unit> target) const {
    try {
        if(target == nullptr)
            throw 0;
        try {
            if(calculateDistance(getPosition(), target->getPosition()) < range_)
                throw 1;
        } catch(int a) {
            std::cout << name_ << " can't attack this unit: it is too far." << std::endl;
            return;
        }
        int damage = calculateDamage(damage_, target->getArmor());
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
               std::shared_ptr<const UnitFactory> buildingFactory) :
        Creature(id, name, xSize, ySize, x, y, health, armor, damage, range), buildingFactory_(buildingFactory) { }

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
               size_t heal, double healRange) : Creature(id, name, xSize, ySize, x, y, health, armor, damage, range),
                                                heal_(heal), healRange_(healRange) { }

size_t Healer::getHeal() const { return heal_; }

double Healer::getHealRange() const { return healRange_; }

void Healer::update() {
    Creature::update();
    healRange_ = std::max(healRange_, 0.0);
}

void Healer::heal(std::shared_ptr<Unit> target) {
    try {
        if(target == nullptr)
            throw 0;
        try {
            if(calculateDistance(getPosition(), target->getPosition()) < range_)
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
