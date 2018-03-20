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
public:
    std::shared_ptr<TownHall> getTownHall(int x, int y) const {
        return std::make_shared<HumanTownHall>(std::dynamic_pointer_cast<const HumanUnitFactory>(shared_from_this()), x, y);
    }
    
    std::shared_ptr<Barracks> getBarracks(int x, int y) const {
        return std::make_shared<HumanBarracks>(std::dynamic_pointer_cast<const HumanUnitFactory>(shared_from_this()), x, y);
    }
    
    std::shared_ptr<Worker> getWorker(int x, int y) const {
        return std::make_shared<HumanWorker>(std::dynamic_pointer_cast<const HumanUnitFactory>(shared_from_this()), x, y);
    }
    
    std::shared_ptr<Warrior> getWarrior(int x, int y) const {
        return std::make_shared<HumanWarrior>(x, y);
    }
    
    std::shared_ptr<Archer> getArcher(int x, int y) const {
        return std::make_shared<HumanArcher>(x, y);
    }
    
    std::shared_ptr<Healer> getHealer(int x, int y) const {
        return std::make_shared<HumanHealer>(x, y);
    }
};


#endif /* HumanUnitFactory_hpp */
