//
//  PlayerDirector.cpp
//  
//
//  Created by Роман Климовицкий on 18.03.2018.
//

#include "Player/PlayerDirector.hpp"
#include "Units/HumanUnitFactory.hpp"
#include "Units/OrcUnitFactory.hpp"


PlayerBuilder::PlayerBuilder(const std::string &nickname, const std::shared_ptr<IMap>& map) :
        nickname_(nickname), map_(map) { }

std::shared_ptr<Player> PlayerBuilder::getPlayer() const {
    return std::make_shared<Player>(nickname_, race_, map_);
}


HumanPlayerBuilder::HumanPlayerBuilder(const std::string &nickname, const std::shared_ptr<IMap>& map) :
        PlayerBuilder(nickname, map) { }

void HumanPlayerBuilder::buildRace() { race_ = HUMANS; }


OrcPlayerBuilder::OrcPlayerBuilder(const std::string &nickname, const std::shared_ptr<IMap>& map) :
        PlayerBuilder(nickname, map) { }

void OrcPlayerBuilder::buildRace() { race_ = ORCS; }


PlayerDirector::PlayerDirector() : builder_(nullptr) { }

PlayerDirector::PlayerDirector(const std::shared_ptr<PlayerBuilder>& builder) : builder_(builder) { }

void PlayerDirector::setBuilder(const std::shared_ptr<PlayerBuilder>& builder) { builder_ = builder; }

std::shared_ptr<Player> PlayerDirector::buildPlayer() {
    builder_->buildRace();
    return builder_->getPlayer();
}
