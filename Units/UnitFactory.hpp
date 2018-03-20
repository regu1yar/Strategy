//
//  UnitFactory.hpp
//  
//
//  Created by Роман Климовицкий on 16.03.2018.
//

#ifndef UnitFactory_hpp
#define UnitFactory_hpp

#include <memory>
#include "Units/Building.hpp"
#include "Units/Creature.hpp"


class UnitFactory : public std::enable_shared_from_this<UnitFactory> {
public:
    virtual std::shared_ptr<TownHall> getTownHall(int x, int y) const = 0;
    virtual std::shared_ptr<Barracks> getBarracks(int x, int y) const = 0;
    virtual std::shared_ptr<Worker> getWorker(int x, int y) const = 0;
    virtual std::shared_ptr<Warrior> getWarrior(int x, int y) const = 0;
    virtual std::shared_ptr<Archer> getArcher(int x, int y) const = 0;
    virtual std::shared_ptr<Healer> getHealer(int x, int y) const = 0;
};


#endif /* UnitFactory_hpp */
