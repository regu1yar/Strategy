//
// Created by Роман Климовицкий on 21/04/2018.
//

#ifndef MYSTRATEGY_UNITCOST_HPP
#define MYSTRATEGY_UNITCOST_HPP

#include <map>


class UnitCost {
private:
    std::map<size_t, size_t> unitCosts_;

public:
    UnitCost();

    size_t getCost(size_t id) const;
    void setNewCost(size_t id, size_t newCost);
};


class UnitCostSingleton {
private:
    static std::shared_ptr<UnitCost> unitCost_;

public:
    UnitCostSingleton() = delete;
    ~UnitCostSingleton() = delete;
    UnitCostSingleton(const UnitCostSingleton&) = delete;
    UnitCostSingleton& operator=(const UnitCostSingleton&) = delete;

    static std::shared_ptr<UnitCost> costs();
};


#endif //MYSTRATEGY_UNITCOST_HPP
