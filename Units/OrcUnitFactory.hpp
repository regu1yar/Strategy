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
public:
    std::shared_ptr<TownHall> getTownHall(int x, int y) const {
        return std::make_shared<OrcTownHall>(std::dynamic_pointer_cast<const OrcUnitFactory>(shared_from_this()), x, y);
    }
    
    std::shared_ptr<Barracks> getBarracks(int x, int y) const {
        return std::make_shared<OrcBarracks>(std::dynamic_pointer_cast<const OrcUnitFactory>(shared_from_this()), x, y);
    }
    
    std::shared_ptr<Worker> getWorker(int x, int y) const {
        return std::make_shared<OrcWorker>(std::dynamic_pointer_cast<const OrcUnitFactory>(shared_from_this()), x, y);
    }
    
    std::shared_ptr<Warrior> getWarrior(int x, int y) const {
        return std::make_shared<OrcWarrior>(x, y);
    }
    
    std::shared_ptr<Archer> getArcher(int x, int y) const {
        return std::make_shared<OrcArcher>(x, y);
    }
    
    std::shared_ptr<Healer> getHealer(int x, int y) const {
        return std::make_shared<OrcHealer>(x, y);
    }
};


#endif /* OrcUnitFactory_hpp */
