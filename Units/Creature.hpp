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
#include "Units/Unit.hpp"


class Creature : public Unit {
protected:
    int damage_;
    double range_;
    
public:
    Creature(size_t id, std::string name, size_t xSize, size_t ySize,
             int x, int y, int health, int armor, int damage, double range);
    
    int getDamage() const;
    double getRange() const;
    
    void update();
    
    void attack(std::shared_ptr<Unit> target) const;
    // Currently without any borders
    void moveTo(int x, int y);
    void moveBy(int x, int y);
};


class UnitFactory;
class TownHall;
class Barracks;
class Worker : public Creature {
protected:
    std::shared_ptr<UnitFactory> buildingFactory_;
    
public:
    Worker(size_t id, std::string name, size_t xSize, size_t ySize,
           int x, int y, int health, int armor, int damage, double range,
           std::shared_ptr<UnitFactory> buildingFactory);
    
    // Currently without any borders
    std::shared_ptr<TownHall> buildTownHall() const;
    std::shared_ptr<TownHall> buildTownHall(int x, int y);
    std::shared_ptr<Barracks> buildBarracks() const;
    std::shared_ptr<Barracks> buildBarracks(int x, int y);
};


class Warrior : public Creature {
public:
    Warrior(size_t id, std::string name, size_t xSize, size_t ySize,
            int x, int y, int health, int armor, int damage, double range);
};


class Archer : public Creature {
public:
    Archer(size_t id, std::string name, size_t xSize, size_t ySize,
            int x, int y, int health, int armor, int damage, double range);
};


class Healer : public Creature {
protected:
    size_t heal_;
    double healRange_;
    
public:
    Healer(size_t id, std::string name, size_t xSize, size_t ySize,
           int x, int y, int health, int armor, int damage,
           double range, size_t heal, double healRange);
    
    void heal(std::shared_ptr<Unit> target);
};


#endif /* Creature_hpp */
