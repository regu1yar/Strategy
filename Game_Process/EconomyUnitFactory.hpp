//
// Created by Роман Климовицкий on 21/04/2018.
//

#ifndef EconomyUnitFactory_hpp
#define EconomyUnitFactory_hpp

#include "Units/UnitFactory.hpp"
#include "Game_Process/Economy.hpp"


class EconomyUnitFactoryDecorator : public UnitFactory {
private:
    std::shared_ptr<UnitFactory> factory_;
    Race race_;
    mutable std::shared_ptr<IEconomy> economy_;

public:
    EconomyUnitFactoryDecorator(std::shared_ptr<UnitFactory> factory,
                                Race race,
                                std::shared_ptr<IEconomy> economy = std::make_shared<Economy>());

    virtual std::shared_ptr<TownHall> getTownHall(size_t x, size_t y) const;
    virtual std::shared_ptr<Barracks> getBarracks(size_t x, size_t y) const;
    virtual std::shared_ptr<Worker> getWorker(size_t x, size_t y) const;
    virtual std::shared_ptr<Warrior> getWarrior(size_t x, size_t y) const;
    virtual std::shared_ptr<Archer> getArcher(size_t x, size_t y) const;
    virtual std::shared_ptr<Healer> getHealer(size_t x, size_t y) const;
};


#endif /* EconomyUnitFactory_hpp */
