//
//  HumanUnits.cpp
//  
//
//  Created by Роман Климовицкий on 17.03.2018.
//

#include "Units/HumanUnits.hpp"
#include "Units/HumanUnitFactory.hpp"


const size_t HumanTownHall::id = HUMANS + BUILDING + TOWN_HALL;
const std::string HumanTownHall::name = "Town Hall";
const size_t HumanTownHall::xSize = 2;
const size_t HumanTownHall::ySize = 2;
const int HumanTownHall::defaultStartHealth = 1000;
const int HumanTownHall::defaultStartArmor = 10;

HumanTownHall::HumanTownHall(const std::shared_ptr<const HumanUnitFactory> &factory, int x, int y,
                             int health, int armor) : TownHall(id, name, xSize, ySize, x, y, defaultStartHealth, health, armor,
                                                               std::dynamic_pointer_cast<const UnitFactory>(factory)) { }


const size_t HumanBarracks::id = HUMANS + BUILDING + BARRACKS;
const std::string HumanBarracks::name = "Barracks";
const size_t HumanBarracks::xSize = 2;
const size_t HumanBarracks::ySize = 2;
const int HumanBarracks::defaultStartHealth = 800;
const int HumanBarracks::defaultStartArmor = 8;

HumanBarracks::HumanBarracks(const std::shared_ptr<const HumanUnitFactory> &factory, int x, int y,
                             int health, int armor) : Barracks(id, name, xSize, ySize, x, y, defaultStartHealth, health, armor,
                                                               std::dynamic_pointer_cast<const UnitFactory>(factory)) { }


const size_t HumanWorker::id = HUMANS + CREATURE + WORKER;
const std::string HumanWorker::name = "Peasant";
const size_t HumanWorker::xSize = 1;
const size_t HumanWorker::ySize = 1;
const int HumanWorker::defaultStartHealth = 100;
const int HumanWorker::defaultStartArmor = 0;
const int HumanWorker::defaultStartDamage = 4;
const double HumanWorker::defaultStartAttackRange = 1.5;
const double HumanWorker::defaultStartMoveRange = 10;

HumanWorker::HumanWorker(const std::shared_ptr<const HumanUnitFactory> &factory, int x, int y,
                         int health, int armor, int damage, double attackRange, double moveRange) :
        Worker(id, name, xSize, ySize, x, y, defaultStartHealth, health, armor, damage, attackRange, moveRange,
               std::dynamic_pointer_cast<const UnitFactory>(factory)) { }


const size_t HumanWarrior::id = HUMANS + CREATURE + WARRIOR;
const std::string HumanWarrior::name = "Footman";
const size_t HumanWarrior::xSize = 1;
const size_t HumanWarrior::ySize = 1;
const int HumanWarrior::defaultStartHealth = 250;
const int HumanWarrior::defaultStartArmor = 2;
const int HumanWarrior::defaultStartDamage = 15;
const double HumanWarrior::defaultStartAttackRange = 1.5;
const double HumanWarrior::defaultStartMoveRange = 6;

HumanWarrior::HumanWarrior(int x, int y, int health, int armor, int damage, double attackRange, double moveRange) :
        Warrior(id, name, xSize, ySize, x, y, defaultStartHealth, health, armor, damage, attackRange, moveRange) { }


const size_t HumanArcher::id = HUMANS + CREATURE + ARCHER;
const std::string HumanArcher::name = "Rifleman";
const size_t HumanArcher::xSize = 1;
const size_t HumanArcher::ySize = 1;
const int HumanArcher::defaultStartHealth = 175;
const int HumanArcher::defaultStartArmor = 1;
const int HumanArcher::defaultStartDamage = 20;
const double HumanArcher::defaultStartAttackRange = 7.1;
const double HumanArcher::defaultStartMoveRange = 7;

HumanArcher::HumanArcher(int x, int y, int health, int armor, int damage, double attackRange, double moveRange) :
        Archer(id, name, xSize, ySize, x, y, defaultStartHealth, health, armor, damage, attackRange, moveRange) { }


const size_t HumanHealer::id = HUMANS + CREATURE + HEALER;
const std::string HumanHealer::name = "Priest";
const size_t HumanHealer::xSize = 1;
const size_t HumanHealer::ySize = 1;
const int HumanHealer::defaultStartHealth = 150;
const int HumanHealer::defaultStartArmor = 0;
const int HumanHealer::defaultStartDamage = 5;
const double HumanHealer::defaultStartAttackRange = 4;
const double HumanHealer::defaultStartMoveRange = 8;
const int HumanHealer::defaultStartHeal = 10;
const double HumanHealer::defaultStartHealRange = 3;

HumanHealer::HumanHealer(int x, int y, int health, int armor,
                         int damage, double attackRange, double moveRange, int heal, double healRange) :
        Healer(id, name, xSize, ySize, x, y, defaultStartHealth, health, armor, damage, attackRange, moveRange, heal, healRange) { }
