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
    static const int defaultStartHealth;
    static const int defaultStartArmor;

    explicit HumanTownHall(const std::shared_ptr<const HumanUnitFactory> &factory,
                           int x = 0, int y = 0,
                           int health = defaultStartHealth, int armor = defaultStartArmor);
    
    ~HumanTownHall() { }
};


class HumanBarracks : public Barracks {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int defaultStartHealth;
    static const int defaultStartArmor;

    explicit HumanBarracks(const std::shared_ptr<const HumanUnitFactory> &factory,
                           int x = 0, int y = 0,
                           int health = defaultStartHealth, int armor = defaultStartArmor);
    
    ~HumanBarracks() { }
};


class HumanWorker : public Worker {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int defaultStartHealth;
    static const int defaultStartArmor;
    static const int defaultStartDamage;
    static const double defaultStartAttackRange;
    static const double defaultStartMoveRange;

    explicit HumanWorker(const std::shared_ptr<const HumanUnitFactory> &factory,
                         int x = 0, int y = 0, int health = defaultStartHealth, int armor = defaultStartArmor,
                         int damage = defaultStartDamage, double range = defaultStartAttackRange,
                         double moveRange = defaultStartMoveRange);
    
    ~HumanWorker() { }
};


class HumanWarrior : public Warrior {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int defaultStartHealth;
    static const int defaultStartArmor;
    static const int defaultStartDamage;
    static const double defaultStartAttackRange;
    static const double defaultStartMoveRange;

    explicit HumanWarrior(int x = 0, int y = 0, int health = defaultStartHealth, int armor = defaultStartArmor,
                          int damage = defaultStartDamage, double attackRange = defaultStartAttackRange,
                          double moveRange = defaultStartMoveRange);
    
    ~HumanWarrior() { }
};


class HumanArcher : public Archer {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int defaultStartHealth;
    static const int defaultStartArmor;
    static const int defaultStartDamage;
    static const double defaultStartAttackRange;
    static const double defaultStartMoveRange;

    explicit HumanArcher(int x = 0, int y = 0, int health = defaultStartHealth, int armor = defaultStartArmor,
                         int damage = defaultStartDamage, double attackRange = defaultStartAttackRange,
                         double moveRange = defaultStartMoveRange);
    
    ~HumanArcher() { }
};


class HumanHealer : public Healer {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int defaultStartHealth;
    static const int defaultStartArmor;
    static const int defaultStartDamage;
    static const double defaultStartAttackRange;
    static const double defaultStartMoveRange;
    static const int defaultStartHeal;
    static const double defaultStartHealRange;

    explicit HumanHealer(int x = 0, int y = 0, int health = defaultStartHealth, int armor = defaultStartArmor,
                int damage = defaultStartDamage, double attackRange = defaultStartAttackRange,
                double moveRange = defaultStartMoveRange, int heal = defaultStartHeal,
                double healRange = defaultStartHealRange);
    
    ~HumanHealer() { }
};


#endif /* HumanUnits_hpp */
