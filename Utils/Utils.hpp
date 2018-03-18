//
//  Utils.hpp
//  
//
//  Created by Роман Климовицкий on 17.03.2018.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <ctime>
#include <random>


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


class Utils {
private:
    static const double minDamageMultiplier_;
    static const double maxDamageMultiplier_;
    static const double armorMultiplier_;
    
    static bool random_;
    
public:
    static std::mt19937 generator;
    
    static const int startWorkers_;
    static const int startTownHalls_;
    static const int xStartPositionShift_;
    static const int yStartPositionShift_;
    
    static void initRandom();
    static int getRandom(int form, int to);
    static int calculateDamage(int damage, int armor);
    static double calculateDistance(std::pair<int, int> first,
                                    std::pair<int, int> second);
};



#endif /* Utils_hpp */
