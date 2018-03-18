//
//  OrcUnits.cpp
//  
//
//  Created by Роман Климовицкий on 17.03.2018.
//

#include "Units/OrcUnits.hpp"
#include "Units/OrcUnitFactory.hpp"


const size_t OrcTownHall::id = ORCS + BUILDING + TOWN_HALL;
const std::string OrcTownHall::name = "Great Hall";
const size_t OrcTownHall::xSize = 2;
const size_t OrcTownHall::ySize = 2;
const int OrcTownHall::startHealth = 1200;
const int OrcTownHall::startArmor = 8;

OrcTownHall::OrcTownHall(std::shared_ptr<OrcUnitFactory> factory, int x, int y,
                         int health, int armor) :
TownHall(id, name, xSize, ySize, x, y, health, armor,
         std::dynamic_pointer_cast<UnitFactory>(factory)) { }


const size_t OrcBarracks::id = ORCS + BUILDING + BARRACKS;
const std::string OrcBarracks::name = "Barracks";
const size_t OrcBarracks::xSize = 2;
const size_t OrcBarracks::ySize = 2;
const int OrcBarracks::startHealth = 900;
const int OrcBarracks::startArmor = 7;

OrcBarracks::OrcBarracks(std::shared_ptr<OrcUnitFactory> factory, int x, int y,
                         int health, int armor) :
Barracks(id, name, xSize, ySize, x, y, health, armor,
         std::dynamic_pointer_cast<UnitFactory>(factory)) { }


const size_t OrcWorker::id = ORCS + CREATURE + WORKER;
const std::string OrcWorker::name = "Peon";
const size_t OrcWorker::xSize = 1;
const size_t OrcWorker::ySize = 1;
const int OrcWorker::startHealth = 125;
const int OrcWorker::startArmor = 0;
const int OrcWorker::startDamage = 5;
const double OrcWorker::startRange = 1.5;

OrcWorker::OrcWorker(std::shared_ptr<OrcUnitFactory> factory, int x, int y,
                     int health, int armor, int damage, double range) :
Worker(id, name, xSize, ySize, x, y, health, armor, damage, range,
       std::dynamic_pointer_cast<UnitFactory>(factory)) { }


const size_t OrcWarrior::id = ORCS + CREATURE + WARRIOR;
const std::string OrcWarrior::name = "Grunt";
const size_t OrcWarrior::xSize = 1;
const size_t OrcWarrior::ySize = 1;
const int OrcWarrior::startHealth = 300;
const int OrcWarrior::startArmor = 1;
const int OrcWarrior::startDamage = 17;
const double OrcWarrior::startRange = 1.5;

OrcWarrior::OrcWarrior(int x, int y, int health, int armor, int damage, double range) :
Warrior(id, name, xSize, ySize, x, y, health, armor, damage, range) { }


const size_t OrcArcher::id = ORCS + CREATURE + ARCHER;
const std::string OrcArcher::name = "Headhunter";
const size_t OrcArcher::xSize = 1;
const size_t OrcArcher::ySize = 1;
const int OrcArcher::startHealth = 200;
const int OrcArcher::startArmor = 0;
const int OrcArcher::startDamage = 22;
const double OrcArcher::startRange = 7.1;

OrcArcher::OrcArcher(int x, int y, int health, int armor, int damage, double range) :
Archer(id, name, xSize, ySize, x, y, health, armor, damage, range) { }


const size_t OrcHealer::id = ORCS + CREATURE + HEALER;
const std::string OrcHealer::name = "Witch Doctor";
const size_t OrcHealer::xSize = 1;
const size_t OrcHealer::ySize = 1;
const int OrcHealer::startHealth = 175;
const int OrcHealer::startArmor = 1;
const int OrcHealer::startDamage = 7;
const double OrcHealer::startRange = 3;
const int OrcHealer::startHeal = 7;
const double OrcHealer::startHealRange = 4;

OrcHealer::OrcHealer(int x, int y, int health, int armor,
                     int damage, double range, int heal, double healRange) :
Healer(id, name, xSize, ySize, x, y, health, armor, damage, range, heal, healRange) { }
