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
    std::shared_ptr<IMap> map_;
    Race race_;
    
public:
    explicit PlayerBuilder(const std::string &nickname, const std::shared_ptr<IMap>& map = std::make_shared<Map>());
    virtual ~PlayerBuilder() { }
    
    std::shared_ptr<Player> getPlayer() const;
    
    virtual void buildRace() = 0;
};


class HumanPlayerBuilder : public PlayerBuilder {
public:
    explicit HumanPlayerBuilder(const std::string &nickname, const std::shared_ptr<IMap>& map = std::make_shared<Map>());
    ~HumanPlayerBuilder() { }
    
    virtual void buildRace();
};


class OrcPlayerBuilder : public PlayerBuilder {
public:
    explicit OrcPlayerBuilder(const std::string &nickname, const std::shared_ptr<IMap>& map = std::make_shared<Map>());
    ~OrcPlayerBuilder() { }
    
    virtual void buildRace();
};


class PlayerDirector {
private:
    std::shared_ptr<PlayerBuilder> builder_;
    
public:
    PlayerDirector();
    explicit PlayerDirector(const std::shared_ptr<PlayerBuilder>& builder);
    
    ~PlayerDirector() { }
    
    void setBuilder(const std::shared_ptr<PlayerBuilder>& builder);
    std::shared_ptr<Player> buildPlayer();
};


#endif /* PlayerDirector_hpp */
