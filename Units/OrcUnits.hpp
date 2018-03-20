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
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;

    OrcTownHall(std::shared_ptr<const OrcUnitFactory> factory,
                int x = 0, int y = 0,
                int health = startHealth, int armor = startArmor);
    
    ~OrcTownHall() { }
};


class OrcBarracks : public Barracks {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;

    OrcBarracks(std::shared_ptr<const OrcUnitFactory> factory,
                int x = 0, int y = 0,
                int health = startHealth, int armor = startArmor);
    
    ~OrcBarracks() { }
};


class OrcWorker : public Worker {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    static const int startDamage;
    static const double startRange;

    OrcWorker(std::shared_ptr<const OrcUnitFactory> factory,
              int x = 0, int y = 0,
              int health = startHealth, int armor = startArmor,
              int damage = startDamage, double range = startRange);
    
    ~OrcWorker() { }
};


class OrcWarrior : public Warrior {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    static const int startDamage;
    static const double startRange;

    OrcWarrior(int x = 0, int y = 0,
               int health = startHealth, int armor = startArmor,
               int damage = startDamage, double range = startRange);
    
    ~OrcWarrior() { }
};


class OrcArcher : public Archer {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    static const int startDamage;
    static const double startRange;

    OrcArcher(int x = 0, int y = 0,
              int health = startHealth, int armor = startArmor,
              int damage = startDamage, double range = startRange);
    
    ~OrcArcher() { }
};


class OrcHealer : public Healer {
public:
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

    OrcHealer(int x = 0, int y = 0,
              int health = startHealth, int armor = startArmor,
              int damage = startDamage, double range = startRange,
              int heal = startHeal, double healRange = startHealRange);
    
    ~OrcHealer() { }
};


#endif /* OrcUnits_hpp */
