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
#include "Game_Process/EconomyUnitFactory.hpp"
#include "Map/Map.hpp"


class Player {
private:
    const std::string nickname_;
    const Race race_;
    std::shared_ptr<IMap> map_;
    const size_t xStartPosition_;
    const size_t yStartPosition_;
    std::shared_ptr<IEconomy> economy_;
    std::shared_ptr<UnitFactory> factory_;

    static size_t curXStartPosition_;
    static size_t curYStartPosition_;

    void setStartResources();
    void updateStartPositions();
    
public:
    static const int startWorkers_;
    static const int startTownHalls_;
    static const int xStartPositionShift_;
    static const int yStartPositionShift_;
    static const int startGold_;

    Player(const std::string &nickname, Race race,
           const std::shared_ptr<IMap>& map = std::make_shared<Map>(),
           size_t x = curXStartPosition_, size_t y = curYStartPosition_,
           int startGold = startGold_);
    
    std::string getNickname() const;
    Race getRace() const;
    std::pair<size_t, size_t> getStartPosition() const;
    
    static std::pair<size_t, size_t> getCurStartPosition();
};


#endif /* Player_hpp */
