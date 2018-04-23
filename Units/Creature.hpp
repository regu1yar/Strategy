//
//  Creature.hpp
//  
//
//  Created by Роман Климовицкий on 16.03.2018.
//

#ifndef Creature_hpp
#define Creature_hpp

#include <memory>
#include <iostream>
#include <string>
#include <cmath>
#include "Units/Unit.hpp"


enum Attack {
    SUCCESSFUL_ATTACK = 0,
    SMALL_RANGE_ATTACK,
    BAD_TARGET_ATTACK,
};

enum Move {
    SUCCESSFUL_MOVE = 0,
    SMALL_RANGE_MOVE,
    ENGAGED_MOVE,
    IMPOSSIBLE_MOVE,
};

class Creature : public Unit {
protected:
    int damage_;
    double attackRange_;
    double moveRange_;

    static const double minDamageMultiplier_;
    static const double maxDamageMultiplier_;
    static const double armorMultiplier_;
    static const int minDamage_;
    static const double minAttackRange_;
    static const double minMoveRange_;

    void update();

    static int calculateDamage(int damage, int armor);
    static double calculateDistance(const std::pair<size_t, size_t> &first,
                                    const std::pair<size_t, size_t> &second);
    
public:
    Creature(size_t id, const std::string &name, size_t xSize, size_t ySize, const std::shared_ptr <IMap> &map, size_t x,
             size_t y,
             int maxHealth, int health, int armor,
             int damage = minDamage_, double attackRange = minAttackRange_, double moveRange = minMoveRange_);
    
    int getDamage() const;
    double getAttackRange() const;
    double getMoveRange() const;
    
    Attack attack(std::shared_ptr<Unit> target) const;
    Move moveTo(size_t x, size_t y);
    Move moveBy(int x, int y);
};


class UnitFactory;
class TownHall;
class Barracks;
class Worker : public Creature {
protected:
    std::shared_ptr<const UnitFactory> buildingFactory_;
    
public:
    Worker(size_t id, const std::string &name, size_t xSize, size_t ySize, const std::shared_ptr <IMap> &map,
           size_t x, size_t y, int maxHealth, int health, int armor, int damage, double attackRange, double moveRange,
           const std::shared_ptr<const UnitFactory> &buildingFactory);
    
    // Currently without any borders
    std::shared_ptr<TownHall> buildTownHall() const;
    std::shared_ptr<TownHall> buildTownHall(size_t x, size_t y);
    std::shared_ptr<Barracks> buildBarracks() const;
    std::shared_ptr<Barracks> buildBarracks(size_t x, size_t y);
};


class Warrior : public Creature {
public:
    Warrior(size_t id, const std::string &name, size_t xSize, size_t ySize, const std::shared_ptr <IMap> &map,
            size_t x, size_t y, int maxHealth, int health, int armor, int damage, double attackRange, double moveRange);
};


class Archer : public Creature {
public:
    Archer(size_t id, const std::string &name, size_t xSize, size_t ySize, const std::shared_ptr <IMap> &map,
           size_t x, size_t y, int maxHealth, int health, int armor, int damage, double attackRange, double moveRange);
};


enum Heal {
    SUCCESSFUL_HEAL = 0,
    SMALL_RANGE_HEAL,
    BAD_TARGET_HEAL
};

class Healer : public Creature {
protected:
    int heal_;
    double healRange_;

    static const int minHeal_;
    static const double minHealRange_;

    void update();
    
public:
    Healer(size_t id, const std::string &name, size_t xSize, size_t ySize, const std::shared_ptr <IMap> &map, size_t x,
           size_t y,
           int maxHealth, int health, int armor, int damage = minDamage_, double attackRange = minAttackRange_,
           double moveRange = minMoveRange_, int heal = minHeal_, double healRange = minHealRange_);

    int getHeal() const;
    double getHealRange() const;
    
    Heal heal(std::shared_ptr<Creature> target);
};


#endif /* Creature_hpp */
