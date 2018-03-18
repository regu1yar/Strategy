//
//  Player.hpp
//  
//
//  Created by Роман Климовицкий on 18.03.2018.
//

#ifndef Player_hpp
#define Player_hpp

#include <string>
#include <map>
#include <memory>
#include "Utils/Utils.hpp"
#include "Units/Unit.hpp"
#include "Units/UnitFactory.hpp"


class Player {
private:
    const std::string nickname_;
    const Race race_;
    std::shared_ptr<UnitFactory> factory_;
    std::map<size_t, std::shared_ptr<Unit>> units_;
    const int xStartPosition_;
    const int yStartPosition_;
    
    static int curXStartPosition_;
    static int curYStartPosition_;
    
public:
    Player(std::string nickname, Race race, std::shared_ptr<UnitFactory> factory,
           int x = curXStartPosition_, int y = curYStartPosition_);
    
    std::string getNickname() const;
    Race getRace() const;
    std::pair<int, int> getStartPosition() const;
    size_t getUnitsNumber() const;
    
    static std::pair<int, int> getCurStartPosition();
};


#endif /* Player_hpp */
