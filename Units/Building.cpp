//
//  Building.cpp
//  
//
//  Created by Роман Климовицкий on 16.03.2018.
//

#include "Units/Building.hpp"
#include "Units/UnitFactory.hpp"
#include "Units/Creature.hpp"


Building::Building(size_t id, std::string name, size_t xSize, size_t ySize, int x, int y,
                   int health, int armor, std::shared_ptr<UnitFactory> creatureFactory) :
Unit(id, name, xSize, ySize, x, y, health, armor), creatureFactory_(creatureFactory) { }


TownHall::TownHall(size_t id, std::string name, size_t xSize, size_t ySize, int x, int y,
                   int health, int armor, std::shared_ptr<UnitFactory> creatureFactory) :
Building(id, name, xSize, ySize, x, y, health, armor, creatureFactory) { }

std::shared_ptr<Worker> TownHall::createWorker() const {
    std::shared_ptr<Worker> worker = creatureFactory_->getWorker(x_ + xSize_, y_ + ySize_);
    std::cout << worker->getName() << " was produced by " << name_ << '.' << std::endl;
    return worker;
}


Barracks::Barracks(size_t id, std::string name, size_t xSize, size_t ySize, int x, int y,
                   int health, int armor, std::shared_ptr<UnitFactory> creatureFactory) :
Building(id, name, xSize, ySize, x, y, health, armor, creatureFactory) { }

std::shared_ptr<Warrior> Barracks::createWarrior() const {
    std::shared_ptr<Warrior> warrior = creatureFactory_->getWarrior(x_ + xSize_, y_ + ySize_);
    std::cout << warrior->getName() << " was produced by " << name_ << '.' << std::endl;
    return warrior;
}

std::shared_ptr<Archer> Barracks::createArcher() const {
    std::shared_ptr<Archer> archer = creatureFactory_->getArcher(x_ + xSize_, y_ + ySize_);
    std::cout << archer->getName() << " was produced by " << name_ << '.' << std::endl;
    return archer;
}

std::shared_ptr<Healer> Barracks::createHealer() const {
    std::shared_ptr<Healer> healer = creatureFactory_->getHealer(x_ + xSize_, y_ + ySize_);
    std::cout << healer->getName() << " was produced by " << name_ << '.' << std::endl;
    return healer;
    }
