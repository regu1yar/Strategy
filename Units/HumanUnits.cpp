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
const int HumanTownHall::startHealth = 1000;
const int HumanTownHall::startArmor = 10;

HumanTownHall::HumanTownHall(std::shared_ptr<const HumanUnitFactory> factory, int x, int y,
                             int health, int armor) : TownHall(id, name, xSize, ySize, x, y, health, armor,
                                                               std::dynamic_pointer_cast<const UnitFactory>(factory)) { }


const size_t HumanBarracks::id = HUMANS + BUILDING + BARRACKS;
const std::string HumanBarracks::name = "Barracks";
const size_t HumanBarracks::xSize = 2;
const size_t HumanBarracks::ySize = 2;
const int HumanBarracks::startHealth = 800;
const int HumanBarracks::startArmor = 8;

HumanBarracks::HumanBarracks(std::shared_ptr<const HumanUnitFactory> factory, int x, int y,
                             int health, int armor) : Barracks(id, name, xSize, ySize, x, y, health, armor,
                                                               std::dynamic_pointer_cast<const UnitFactory>(factory)) { }


const size_t HumanWorker::id = HUMANS + CREATURE + WORKER;
const std::string HumanWorker::name = "Peasant";
const size_t HumanWorker::xSize = 1;
const size_t HumanWorker::ySize = 1;
const int HumanWorker::startHealth = 100;
const int HumanWorker::startArmor = 0;
const int HumanWorker::startDamage = 4;
const double HumanWorker::startRange = 1.5;

HumanWorker::HumanWorker(std::shared_ptr<const HumanUnitFactory> factory, int x, int y,
                         int health, int armor, int damage, double range) :
        Worker(id, name, xSize, ySize, x, y, health, armor, damage, range,
               std::dynamic_pointer_cast<const UnitFactory>(factory)) { }


const size_t HumanWarrior::id = HUMANS + CREATURE + WARRIOR;
const std::string HumanWarrior::name = "Footman";
const size_t HumanWarrior::xSize = 1;
const size_t HumanWarrior::ySize = 1;
const int HumanWarrior::startHealth = 250;
const int HumanWarrior::startArmor = 2;
const int HumanWarrior::startDamage = 15;
const double HumanWarrior::startRange = 1.5;

HumanWarrior::HumanWarrior(int x, int y, int health, int armor, int damage, double range) :
        Warrior(id, name, xSize, ySize, x, y, health, armor, damage, range) { }


const size_t HumanArcher::id = HUMANS + CREATURE + ARCHER;
const std::string HumanArcher::name = "Rifleman";
const size_t HumanArcher::xSize = 1;
const size_t HumanArcher::ySize = 1;
const int HumanArcher::startHealth = 175;
const int HumanArcher::startArmor = 1;
const int HumanArcher::startDamage = 20;
const double HumanArcher::startRange = 7.1;

HumanArcher::HumanArcher(int x, int y, int health, int armor, int damage, double range) :
        Archer(id, name, xSize, ySize, x, y, health, armor, damage, range) { }


const size_t HumanHealer::id = HUMANS + CREATURE + HEALER;
const std::string HumanHealer::name = "Priest";
const size_t HumanHealer::xSize = 1;
const size_t HumanHealer::ySize = 1;
const int HumanHealer::startHealth = 150;
const int HumanHealer::startArmor = 0;
const int HumanHealer::startDamage = 5;
const double HumanHealer::startRange = 4;
const int HumanHealer::startHeal = 10;
const double HumanHealer::startHealRange = 3;

HumanHealer::HumanHealer(int x, int y, int health, int armor,
                         int damage, double range, int heal, double healRange) :
        Healer(id, name, xSize, ySize, x, y, health, armor, damage, range, heal, healRange) { }
