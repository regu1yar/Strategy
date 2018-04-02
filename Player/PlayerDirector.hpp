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
    PlayerBuilder(const std::string &nickname);
    virtual ~PlayerBuilder() { }
    
    std::shared_ptr<Player> getPlayer() const;
    
    virtual void buildRace() = 0;
    virtual void buildFactory() = 0;
};


class HumanPlayerBuilder : public PlayerBuilder {
public:
    HumanPlayerBuilder(const std::string &nickname);
    ~HumanPlayerBuilder() { }
    
    virtual void buildRace();
    virtual void buildFactory();
};


class OrcPlayerBuilder : public PlayerBuilder {
public:
    OrcPlayerBuilder(const std::string &nickname);
    ~OrcPlayerBuilder() { }
    
    virtual void buildRace();
    virtual void buildFactory();
};


class PlayerDirector {
private:
    std::shared_ptr<PlayerBuilder> builder_;
    
public:
    PlayerDirector();
    PlayerDirector(std::shared_ptr<PlayerBuilder> builder);
    
    ~PlayerDirector() { }
    
    void setBuilder(std::shared_ptr<PlayerBuilder> builder);
    std::shared_ptr<Player> buildPlayer();
};


#endif /* PlayerDirector_hpp */
