//
//  HumanUnits.hpp
//  
//
//  Created by Роман Климовицкий on 17.03.2018.
//

#ifndef HumanUnits_hpp
#define HumanUnits_hpp

#include "Utils/Utils.hpp"
#include "Units/Building.hpp"
#include "Units/Creature.hpp"


class HumanUnitFactory;
class HumanTownHall : public TownHall {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    
public:
    HumanTownHall(std::shared_ptr<const HumanUnitFactory>,
                  int x = 0, int y = 0,
                  int health = startHealth, int armor = startArmor);
    
    ~HumanTownHall() { }
};


class HumanBarracks : public Barracks {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;

    HumanBarracks(std::shared_ptr<const HumanUnitFactory>,
                  int x = 0, int y = 0,
                  int health = startHealth, int armor = startArmor);
    
    ~HumanBarracks() { }
};


class HumanWorker : public Worker {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    static const int startDamage;
    static const double startRange;

    HumanWorker(std::shared_ptr<const HumanUnitFactory>,
                int x = 0, int y = 0,
                int health = startHealth, int armor = startArmor,
                int damage = startDamage, double range = startRange);
    
    ~HumanWorker() { }
};


class HumanWarrior : public Warrior {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    static const int startDamage;
    static const double startRange;

    HumanWarrior(int x = 0, int y = 0,
                  int health = startHealth, int armor = startArmor,
                  int damage = startDamage, double range = startRange);
    
    ~HumanWarrior() { }
};


class HumanArcher : public Archer {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int startHealth;
    static const int startArmor;
    static const int startDamage;
    static const double startRange;

    HumanArcher(int x = 0, int y = 0,
                 int health = startHealth, int armor = startArmor,
                 int damage = startDamage, double range = startRange);
    
    ~HumanArcher() { }
};


class HumanHealer : public Healer {
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

    HumanHealer(int x = 0, int y = 0,
                int health = startHealth, int armor = startArmor,
                int damage = startDamage, double range = startRange,
                int heal = startHeal, double healRange = startHealRange);
    
    ~HumanHealer() { }
};


#endif /* HumanUnits_hpp */
