//
//  PlayerDirector.hpp
//  
//
//  Created by Роман Климовицкий on 18.03.2018.
//

#ifndef PlayerDirector_hpp
#define PlayerDirector_hpp

#include <memory>
#include "Player/Player.hpp"


class PlayerBuilder {
protected:
    std::string nickname_;
    Race race_;
    std::shared_ptr<UnitFactory> factory_;
    
public:
    PlayerBuilder(std::string nickname);
    virtual ~PlayerBuilder() { }
    
    std::shared_ptr<Player> getPlayer() const;
    
    virtual void buildRace() = 0;
    virtual void buildFactory() = 0;
};


class HumanPlayerBuilder : public PlayerBuilder {
public:
    HumanPlayerBuilder(std::string nickname);
    ~HumanPlayerBuilder() { }
    
    virtual void buildRace();
    virtual void buildFactory();
};


class OrcPlayerBuilder : public PlayerBuilder {
public:
    OrcPlayerBuilder(std::string nickname);
    ~OrcPlayerBuilder() { }
    
    virtual void buildRace();
    virtual void buildFactory();
};


class PlayerDirector {
private:
    PlayerBuilder* builder_;
    
public:
    PlayerDirector();
    PlayerDirector(PlayerBuilder* builder);
    
    ~PlayerDirector();
    
    void setBuilder(PlayerBuilder* builder);
    std::shared_ptr<Player> buildPlayer();
};


#endif /* PlayerDirector_hpp */
