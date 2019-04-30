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
const int OrcTownHall::defaultStartHealth = 1200;
const int OrcTownHall::defaultStartArmor = 8;

OrcTownHall::OrcTownHall(const std::shared_ptr<OrcUnitFactory> &factory, const std::shared_ptr<IMap>& map,
                         size_t x, size_t y, int health, int armor) :
        TownHall(id, name, xSize, ySize, map, x, y, defaultStartHealth, health, armor,
                 std::dynamic_pointer_cast<UnitFactory>(factory)) { }


const size_t OrcBarracks::id = ORCS + BUILDING + BARRACKS;
const std::string OrcBarracks::name = "Barracks";
const size_t OrcBarracks::xSize = 2;
const size_t OrcBarracks::ySize = 2;
const int OrcBarracks::defaultStartHealth = 900;
const int OrcBarracks::defaultStartArmor = 7;

OrcBarracks::OrcBarracks(const std::shared_ptr<OrcUnitFactory> &factory, const std::shared_ptr<IMap>& map,
                         size_t x, size_t y, int health, int armor) :
        Barracks(id, name, xSize, ySize, map, x, y, defaultStartHealth, health, armor,
                 std::dynamic_pointer_cast<UnitFactory>(factory)) { }


const size_t OrcWorker::id = ORCS + CREATURE + WORKER;
const std::string OrcWorker::name = "Peon";
const size_t OrcWorker::xSize = 1;
const size_t OrcWorker::ySize = 1;
const int OrcWorker::defaultStartHealth = 125;
const int OrcWorker::defaultStartArmor = 0;
const int OrcWorker::defaultStartDamage = 5;
const double OrcWorker::defaultStartAttackRange = 1.5;
const double OrcWorker::defaultStartMoveRange = 9;

OrcWorker::OrcWorker(const std::shared_ptr<OrcUnitFactory> &factory, const std::shared_ptr<IMap>& map,
                     size_t x, size_t y, int health, int armor, int damage, double attackRange, double moveRange) :
        Worker(id, name, xSize, ySize, map, x, y, defaultStartHealth, health, armor, damage, attackRange, moveRange,
               std::dynamic_pointer_cast<UnitFactory>(factory)) { }


const size_t OrcWarrior::id = ORCS + CREATURE + WARRIOR;
const std::string OrcWarrior::name = "Grunt";
const size_t OrcWarrior::xSize = 1;
const size_t OrcWarrior::ySize = 1;
const int OrcWarrior::defaultStartHealth = 300;
const int OrcWarrior::defaultStartArmor = 1;
const int OrcWarrior::defaultStartDamage = 17;
const double OrcWarrior::defaultStartAttackRange = 1.5;
const double OrcWarrior::defaultStartMoveRange = 5;

OrcWarrior::OrcWarrior(const std::shared_ptr<IMap>& map, size_t x, size_t y, int health, int armor, int damage,
                       double attackRange, double moveRange) :
        Warrior(id, name, xSize, ySize, map, x, y, defaultStartHealth, health, armor, damage, attackRange, moveRange) { }


const size_t OrcArcher::id = ORCS + CREATURE + ARCHER;
const std::string OrcArcher::name = "Headhunter";
const size_t OrcArcher::xSize = 1;
const size_t OrcArcher::ySize = 1;
const int OrcArcher::defaultStartHealth = 200;
const int OrcArcher::defaultStartArmor = 0;
const int OrcArcher::defaultStartDamage = 22;
const double OrcArcher::defaultStartAttackRange = 7.1;
const double OrcArcher::defaultStartMoveRange = 7;

OrcArcher::OrcArcher(const std::shared_ptr<IMap>& map, size_t x, size_t y, int health, int armor, int damage,
                     double attackRange, double moveRange) :
        Archer(id, name, xSize, ySize, map, x, y, defaultStartHealth, health, armor, damage, attackRange, moveRange) { }


const size_t OrcHealer::id = ORCS + CREATURE + HEALER;
const std::string OrcHealer::name = "Witch Doctor";
const size_t OrcHealer::xSize = 1;
const size_t OrcHealer::ySize = 1;
const int OrcHealer::defaultStartHealth = 175;
const int OrcHealer::defaultStartArmor = 1;
const int OrcHealer::defaultStartDamage = 7;
const double OrcHealer::defaultStartAttackRange = 3;
const double OrcHealer::defaultStartMoveRange = 6;
const int OrcHealer::defaultStartHeal = 7;
const double OrcHealer::defaultStartHealRange = 4;

OrcHealer::OrcHealer(const std::shared_ptr<IMap>& map, size_t x, size_t y, int health, int armor,
                     int damage, double attackRange, double moveRange, int heal, double healRange) :
        Healer(id, name, xSize, ySize, map, x, y, defaultStartHealth, health, armor, damage, attackRange, moveRange,
               heal, healRange) { }
