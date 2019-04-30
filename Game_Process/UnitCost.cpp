//
// Created by Роман Климовицкий on 21/04/2018.
//

#include "UnitCost.hpp"
#include "Units/Unit.hpp"


UnitCost::UnitCost() {
    unitCosts_[HUMANS + BUILDING + TOWN_HALL] = 500;
    unitCosts_[HUMANS + BUILDING + BARRACKS] = 400;

    unitCosts_[HUMANS + CREATURE + WORKER] = 50;
    unitCosts_[HUMANS + CREATURE + WARRIOR] = 100;
    unitCosts_[HUMANS + CREATURE + ARCHER] = 120;
    unitCosts_[HUMANS + CREATURE + HEALER] = 140;

    unitCosts_[ORCS + BUILDING + TOWN_HALL] = 400;
    unitCosts_[ORCS + BUILDING + BARRACKS] = 350;

    unitCosts_[ORCS + CREATURE + WORKER] = 30;
    unitCosts_[ORCS + CREATURE + WARRIOR] = 120;
    unitCosts_[ORCS + CREATURE + ARCHER] = 100;
    unitCosts_[ORCS + CREATURE + HEALER] = 150;
}

size_t UnitCost::getCost(size_t id) const {
    if (unitCosts_.find(id) == unitCosts_.end())
        return -1;
    return unitCosts_.at(id);
}
void UnitCost::setNewCost(size_t id, size_t newCost) {
    if (unitCosts_.find(id) == unitCosts_.end())
        return;
    unitCosts_[id] = newCost;
}

std::shared_ptr<UnitCost> UnitCostSingleton::unitCost_ = nullptr;

std::shared_ptr<UnitCost> UnitCostSingleton::costs() {
    if (unitCost_ == nullptr)
        unitCost_ = std::make_shared<UnitCost>();
    return unitCost_;
}