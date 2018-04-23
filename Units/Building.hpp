//
//  Building.hpp
//  
//
//  Created by Роман Климовицкий on 16.03.2018.
//

#ifndef Building_hpp
#define Building_hpp

#include <memory>
#include <iostream>
#include "Units/Unit.hpp"

class UnitFactory;
class Building : public Unit {
protected:
    std::shared_ptr<const UnitFactory> creatureFactory_;
    
public:
    Building(size_t id, const std::string &name, size_t xSize, size_t ySize, const std::shared_ptr <IMap> &map,
             size_t x, size_t y, int maxHealth, int health, int armor,
             const std::shared_ptr<const UnitFactory> &creatureFactory);
};

class Worker;
class TownHall : public Building {
public:
    TownHall(size_t id, const std::string &name, size_t xSize, size_t ySize, const std::shared_ptr <IMap> &map,
             size_t x, size_t y, int maxHealth, int health, int armor,
             const std::shared_ptr<const UnitFactory> &creatureFactory);
    
    std::shared_ptr<Worker> createWorker() const;
};


class Warrior;
class Archer;
class Healer;
class Barracks : public Building {
public:
    Barracks(size_t id, const std::string &name, size_t xSize, size_t ySize, const std::shared_ptr <IMap> &map,
             size_t x, size_t y, int maxHealth, int health, int armor,
             const std::shared_ptr<const UnitFactory> &creatureFactory);
    
    std::shared_ptr<Warrior> createWarrior() const;
    std::shared_ptr<Archer> createArcher() const;
    std::shared_ptr<Healer> createHealer() const;
};


#endif /* Building_hpp */
