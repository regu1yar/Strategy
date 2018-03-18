//
//  OrcUnits.hpp
//  
//
//  Created by Роман Климовицкий on 17.03.2018.
//

#ifndef OrcUnits_hpp
#define OrcUnits_hpp

#include "Utils/Utils.hpp"
#include "Units/Building.hpp"
#include "Units/Creature.hpp"


class OrcUnitFactory;
class OrcTownHall : public TownHall {
private:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    
public:
    OrcTownHall(std::shared_ptr<OrcUnitFactory> factory,
                int x = 0, int y = 0,
                int health = startHealth, int armor = startArmor);
    
    ~OrcTownHall() { }
};


class OrcBarracks : public Barracks {
private:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    
public:
    OrcBarracks(std::shared_ptr<OrcUnitFactory> factory,
                int x = 0, int y = 0,
                int health = startHealth, int armor = startArmor);
    
    ~OrcBarracks() { }
};


class OrcWorker : public Worker {
private:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    static const int startDamage;
    static const double startRange;
    
public:
    OrcWorker(std::shared_ptr<OrcUnitFactory> factory,
              int x = 0, int y = 0,
              int health = startHealth, int armor = startArmor,
              int damage = startDamage, double range = startRange);
    
    ~OrcWorker() { }
};


class OrcWarrior : public Warrior {
private:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    static const int startDamage;
    static const double startRange;
    
public:
    OrcWarrior(int x = 0, int y = 0,
               int health = startHealth, int armor = startArmor,
               int damage = startDamage, double range = startRange);
    
    ~OrcWarrior() { }
};


class OrcArcher : public Archer {
private:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    static const int startDamage;
    static const double startRange;
    
public:
    OrcArcher(int x = 0, int y = 0,
              int health = startHealth, int armor = startArmor,
              int damage = startDamage, double range = startRange);
    
    ~OrcArcher() { }
};


class OrcHealer : public Healer {
private:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    static const int startDamage;
    static const double startRange;
    static const int startHeal;
    static const double startHealRange;
    
public:
    OrcHealer(int x = 0, int y = 0,
              int health = startHealth, int armor = startArmor,
              int damage = startDamage, double range = startRange,
              int heal = startHeal, double healRange = startRange);
    
    ~OrcHealer() { }
};


#endif /* OrcUnits_hpp */
