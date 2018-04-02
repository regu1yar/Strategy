//
//  Unit.hpp
//  
//
//  Created by Роман Климовицкий on 16.03.2018.
//

#ifndef Unit_hpp
#define Unit_hpp

#include <string>
#include <algorithm>


enum Race {
    HUMANS = 0,
    ORCS = 100
};

enum UnitType {
    BUILDING = 0,
    CREATURE = 10
};

enum BuildingType {
    TOWN_HALL = 0,
    BARRACKS
};

enum CreatureType {
    WORKER = 0,
    WARRIOR,
    ARCHER,
    HEALER
};


class Unit {
protected:
    const size_t uniqueId_;
    const size_t id_;
    const std::string name_;
    const size_t xSize_;
    const size_t ySize_;
    int x_;
    int y_;
    int maxHealth_;
    int health_;
    int armor_;
    
    static size_t counter_;

    void update();
    
public:
    Unit(size_t id, const std::string &name, size_t xSize, size_t ySize,
         int x, int y, int maxHealth, int health, int armor);
    virtual ~Unit() { }
    
    size_t getUniqueId() const;
    size_t getId() const;
    std::string getName() const;
    std::pair<size_t, size_t> getSize() const;
    std::pair<int, int> getPosition() const;
    int getMaxHealth() const;
    int getHealth() const;
    int getArmor() const;

    void takeDamage(int damage); // Clear damage
    void takeHeal(int heal);

    static void setCounterToZero();
};


#endif /* Unit_hpp */
