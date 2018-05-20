//
//  OrcUnitFactory.hpp
//  
//
//  Created by Роман Климовицкий on 17.03.2018.
//

#ifndef OrcUnitFactory_hpp
#define OrcUnitFactory_hpp

#include<memory>
#include "Units/UnitFactory.hpp"
#include "Units/OrcUnits.hpp"


class OrcUnitFactory : public UnitFactory {
private:
    std::shared_ptr<IMap> map_;

public:
    explicit OrcUnitFactory(const std::shared_ptr<IMap>& map = std::make_shared<Map>()) : map_(map) { }

    virtual std::shared_ptr<TownHall> getTownHall(size_t x, size_t y) const {
        std::shared_ptr<OrcTownHall> unit =  std::make_shared<OrcTownHall>(
                std::dynamic_pointer_cast<OrcUnitFactory>(std::const_pointer_cast<UnitFactory>(shared_from_this())),
                        map_, x, y);
        unit->putOnMap();
        return unit;
    }

    virtual std::shared_ptr<Barracks> getBarracks(size_t x, size_t y) const {
        std::shared_ptr<OrcBarracks> unit =  std::make_shared<OrcBarracks>(
                std::dynamic_pointer_cast<OrcUnitFactory>(std::const_pointer_cast<UnitFactory>(shared_from_this())),
                        map_, x, y);
        unit->putOnMap();
        return unit;
    }

    virtual std::shared_ptr<Worker> getWorker(size_t x, size_t y) const {
        std::shared_ptr<OrcWorker> unit =  std::make_shared<OrcWorker>(
                std::dynamic_pointer_cast<OrcUnitFactory>(std::const_pointer_cast<UnitFactory>(shared_from_this())),
                        map_, x, y);
        unit->putOnMap();
        return unit;
    }

    virtual std::shared_ptr<Warrior> getWarrior(size_t x, size_t y) const {
        std::shared_ptr<OrcWarrior> unit =  std::make_shared<OrcWarrior>(map_, x, y);
        unit->putOnMap();
        return unit;
    }

    virtual std::shared_ptr<Archer> getArcher(size_t x, size_t y) const {
        std::shared_ptr<OrcArcher> unit =  std::make_shared<OrcArcher>(map_, x, y);
        unit->putOnMap();
        return unit;
    }

    virtual std::shared_ptr<Healer> getHealer(size_t x, size_t y) const {
        std::shared_ptr<OrcHealer> unit =  std::make_shared<OrcHealer>(map_, x, y);
        unit->putOnMap();
        return unit;
    }
};


#endif /* OrcUnitFactory_hpp */
