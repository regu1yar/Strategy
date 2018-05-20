//
//  HumanUnitFactory.hpp
//  
//
//  Created by Роман Климовицкий on 17.03.2018.
//

#ifndef HumanUnitFactory_hpp
#define HumanUnitFactory_hpp

#include "Units/UnitFactory.hpp"
#include "Units/HumanUnits.hpp"


class HumanUnitFactory : public UnitFactory {
private:
    std::shared_ptr<IMap> map_;

public:
    explicit HumanUnitFactory(const std::shared_ptr<IMap>& map = std::make_shared<Map>()) : map_(map) { }

    virtual std::shared_ptr<TownHall> getTownHall(size_t x, size_t y) const {
        std::shared_ptr<HumanTownHall> unit = std::make_shared<HumanTownHall>(
                std::dynamic_pointer_cast<HumanUnitFactory>(std::const_pointer_cast<UnitFactory>(shared_from_this())),
                        map_, x, y);
        unit->putOnMap();
        return unit;
    }

    virtual std::shared_ptr<Barracks> getBarracks(size_t x, size_t y) const {
        std::shared_ptr<HumanBarracks> unit = std::make_shared<HumanBarracks>(
                std::dynamic_pointer_cast<HumanUnitFactory>(std::const_pointer_cast<UnitFactory>(shared_from_this())),
                        map_, x, y);
        unit->putOnMap();
        return unit;
    }

    virtual std::shared_ptr<Worker> getWorker(size_t x, size_t y) const {
        std::shared_ptr<HumanWorker> unit = std::make_shared<HumanWorker>(
                std::dynamic_pointer_cast<HumanUnitFactory>(std::const_pointer_cast<UnitFactory>(shared_from_this())),
                        map_, x, y);
        unit->putOnMap();
        return unit;
    }

    virtual std::shared_ptr<Warrior> getWarrior(size_t x, size_t y) const {
        std::shared_ptr<HumanWarrior> unit =  std::make_shared<HumanWarrior>(map_, x, y);
        unit->putOnMap();
        return unit;
    }

    virtual std::shared_ptr<Archer> getArcher(size_t x, size_t y) const {
        std::shared_ptr<HumanArcher> unit =  std::make_shared<HumanArcher>(map_, x, y);
        unit->putOnMap();
        return unit;
    }

    virtual std::shared_ptr<Healer> getHealer(size_t x, size_t y) const {
        std::shared_ptr<HumanHealer> unit =  std::make_shared<HumanHealer>(map_, x, y);
        unit->putOnMap();
        return unit;
    }
};


#endif /* HumanUnitFactory_hpp */
