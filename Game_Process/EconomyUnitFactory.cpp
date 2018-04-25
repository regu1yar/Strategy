//
// Created by Роман Климовицкий on 21/04/2018.
//

#include "EconomyUnitFactory.hpp"
#include "Game_Process/UnitCost.hpp"


EconomyUnitFactoryDecorator::EconomyUnitFactoryDecorator(std::shared_ptr<UnitFactory> factory,
                                                         Race race,
                                                         std::shared_ptr<IEconomy> economy) :
        factory_(factory), race_(race), economy_(economy) { }


std::shared_ptr<TownHall> EconomyUnitFactoryDecorator::getTownHall(size_t x, size_t y) const {
    if (economy_->expense(UnitCostSingleton::costs()->getCost(race_ + BUILDING + TOWN_HALL)))
        return factory_->getTownHall(x, y);
    else
        return nullptr;
}

std::shared_ptr<Barracks> EconomyUnitFactoryDecorator::getBarracks(size_t x, size_t y) const {
    if (economy_->expense(UnitCostSingleton::costs()->getCost(race_ + BUILDING + BARRACKS)))
        return factory_->getBarracks(x, y);
    else
        return nullptr;
}

std::shared_ptr<Worker> EconomyUnitFactoryDecorator::getWorker(size_t x, size_t y) const {
    if (economy_->expense(UnitCostSingleton::costs()->getCost(race_ + CREATURE + WORKER)))
        return factory_->getWorker(x, y);
    else
        return nullptr;
}

std::shared_ptr<Warrior> EconomyUnitFactoryDecorator::getWarrior(size_t x, size_t y) const {
    if (economy_->expense(UnitCostSingleton::costs()->getCost(race_ + CREATURE + WARRIOR)))
        return factory_->getWarrior(x, y);
    else
        return nullptr;
}

std::shared_ptr<Archer> EconomyUnitFactoryDecorator::getArcher(size_t x, size_t y) const {
    if (economy_->expense(UnitCostSingleton::costs()->getCost(race_ + CREATURE + ARCHER)))
        return factory_->getArcher(x, y);
    else
        return nullptr;
}

std::shared_ptr<Healer> EconomyUnitFactoryDecorator::getHealer(size_t x, size_t y) const {
    if (economy_->expense(UnitCostSingleton::costs()->getCost(race_ + CREATURE + HEALER)))
        return factory_->getHealer(x, y);
    else
        return nullptr;
}