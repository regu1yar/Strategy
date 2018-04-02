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
    static const int defaultStartHealth;
    static const int defaultStartArmor;

    explicit OrcTownHall(const std::shared_ptr<const OrcUnitFactory> &factory, int x = 0, int y = 0,
                         int health = defaultStartHealth, int armor = defaultStartArmor);
    
    ~OrcTownHall() { }
};


class OrcBarracks : public Barracks {
public:
    static const size_t id;
    static const std::string name;
    static const size_t xSize;
    static const size_t ySize;
    static const int defaultStartHealth;
    static const int defaultStartArmor;

    explicit OrcBarracks(const std::shared_ptr<const OrcUnitFactory> &factory, int x = 0, int y = 0,
                         int health = defaultStartHealth, int armor = defaultStartArmor);
    
    ~OrcBarracks() { }
};


class OrcWorker : public Worker {
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

    explicit OrcWorker(const std::shared_ptr<const OrcUnitFactory> &factory,
                       int x = 0, int y = 0, int health = defaultStartHealth, int armor = defaultStartArmor,
                       int damage = defaultStartDamage, double range = defaultStartAttackRange,
                       double moveRange = defaultStartMoveRange);
    
    ~OrcWorker() { }
};


class OrcWarrior : public Warrior {
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

    explicit OrcWarrior(int x = 0, int y = 0, int health = defaultStartHealth, int armor = defaultStartArmor,
                        int damage = defaultStartDamage, double attackRange = defaultStartAttackRange,
                        double moveRange = defaultStartMoveRange);
    
    ~OrcWarrior() { }
};


class OrcArcher : public Archer {
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

    explicit OrcArcher(int x = 0, int y = 0, int health = defaultStartHealth, int armor = defaultStartArmor,
                       int damage = defaultStartDamage, double attackRange = defaultStartAttackRange,
                       double moveRange = defaultStartMoveRange);
    
    ~OrcArcher() { }
};


class OrcHealer : public Healer {
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

    explicit OrcHealer(int x = 0, int y = 0, int health = defaultStartHealth, int armor = defaultStartArmor,
                       int damage = defaultStartDamage, double attackRange = defaultStartAttackRange,
                       double moveRange = defaultStartMoveRange, int heal = defaultStartHeal,
                       double healRange = defaultStartHealRange);
    
    ~OrcHealer() { }
};


#endif /* OrcUnits_hpp */
