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
const int Creature::minDamage_ = 0;
const double Creature::minAttackRange_ = 0;
const double Creature::minMoveRange_ = 0;

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
                   int x, int y, int maxHealth, int health, int armor, int damage, double attackRange, double moveRange) :
        Unit(id, name, xSize, ySize, x, y, maxHealth, health, armor),
        damage_(damage), attackRange_(attackRange), moveRange_(moveRange) { }

int Creature::getDamage() const { return damage_; }

double Creature::getAttackRange() const { return attackRange_; }

double Creature::getMoveRange() const { return moveRange_; }

void Creature::update() {
    Unit::update();
    damage_ = std::max(damage_, minDamage_);
    attackRange_ = std::max(attackRange_, minAttackRange_);
    moveRange_ = std::max(moveRange_, minMoveRange_);
}

Attack Creature::attack(std::shared_ptr<Unit> target) const {
    if(target == nullptr)
        return BAD_TARGET_ATTACK;
    if(calculateDistance(getPosition(), target->getPosition()) > attackRange_)
        return SMALL_RANGE_ATTACK;
    int damage = calculateDamage(damage_, target->getArmor());
    target->takeDamage(damage);
    return SUCCESSFUL_ATTACK;
}

Move Creature::moveTo(int x, int y) {
    if(calculateDistance({x, y}, getPosition()) > moveRange_)
        return SMALL_RANGE_MOVE;
    x_ = x;
    y_ = y;
    return SUCCESSFUL_MOVE;
}

Move Creature::moveBy(int x, int y) {
    return moveTo(x_ + x, y_ + y);
}


Worker::Worker(size_t id, std::string name, size_t xSize, size_t ySize,
               int x, int y, int maxHealth, int health, int armor, int damage, double attackRange, double moveRange,
               std::shared_ptr<const UnitFactory> buildingFactory) :
        Creature(id, name, xSize, ySize, x, y, maxHealth, health, armor, damage, attackRange, moveRange),
        buildingFactory_(buildingFactory) { }

std::shared_ptr<TownHall> Worker::buildTownHall() const {
    std::shared_ptr<TownHall> townHall = buildingFactory_->getTownHall(x_ + xSize_, y_ + ySize_);
    return townHall;
}

std::shared_ptr<TownHall> Worker::buildTownHall(int x, int y) {
    if(moveTo(x - xSize_, y - ySize_) == SUCCESSFUL_MOVE)
        return buildTownHall();
    else
        return nullptr;
}

std::shared_ptr<Barracks> Worker::buildBarracks() const {
    std::shared_ptr<Barracks> barracks = buildingFactory_->getBarracks(x_ + xSize_, y_ + ySize_);
    return barracks;
}

std::shared_ptr<Barracks> Worker::buildBarracks(int x, int y) {
    if(moveTo(x - xSize_, y - ySize_) == SUCCESSFUL_MOVE)
        return buildBarracks();
    else
        return nullptr;
}


Warrior::Warrior(size_t id, std::string name, size_t xSize, size_t ySize,
                 int x, int y, int maxHealth, int health, int armor, int damage, double attackRange, double moveRange) :
Creature(id, name, xSize, ySize, x, y, maxHealth, health, armor, damage, attackRange, moveRange) { }


Archer::Archer(size_t id, std::string name, size_t xSize, size_t ySize,
                int x, int y, int maxHealth, int health, int armor, int damage, double attackRange, double moveRange) :
Creature(id, name, xSize, ySize, x, y, maxHealth, health, armor, damage, attackRange, moveRange) { }


const int Healer::minHeal_ = 0;
const double Healer::minHealRange_ = 0;

Healer::Healer(size_t id, std::string name, size_t xSize, size_t ySize, int x, int y, int maxHealth,
               int health, int armor, int damage, double attackRange, double moveRange, int heal, double healRange) :
        Creature(id, name, xSize, ySize, x, y, maxHealth, health, armor, damage, attackRange, moveRange),
        heal_(heal), healRange_(healRange) { }

int Healer::getHeal() const { return heal_; }

double Healer::getHealRange() const { return healRange_; }

void Healer::update() {
    Creature::update();
    heal_ = std::max(heal_, minHeal_);
    healRange_ = std::max(healRange_, minHealRange_);
}

Heal Healer::heal(std::shared_ptr<Creature> target) {
    if(target == nullptr)
        return BAD_TARGET_HEAL;
    if(calculateDistance(getPosition(), target->getPosition()) > attackRange_)
        return SMALL_RANGE_HEAL;
    target->takeHeal(heal_);
    return SUCCESSFUL_HEAL;
}
