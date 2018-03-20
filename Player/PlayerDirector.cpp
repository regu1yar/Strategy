//
//  PlayerDirector.cpp
//  
//
//  Created by Роман Климовицкий on 18.03.2018.
//

#include "Player/PlayerDirector.hpp"
#include "Units/HumanUnitFactory.hpp"
#include "Units/OrcUnitFactory.hpp"


PlayerBuilder::PlayerBuilder(std::string nickname) : nickname_(nickname) { }

std::shared_ptr<Player> PlayerBuilder::getPlayer() const {
    return std::make_shared<Player>(nickname_, race_, factory_);
}


HumanPlayerBuilder::HumanPlayerBuilder(std::string nickname) : PlayerBuilder(nickname) { }

void HumanPlayerBuilder::buildRace() { race_ = HUMANS; }

void HumanPlayerBuilder::buildFactory() { factory_ = std::make_shared<HumanUnitFactory>(); }


OrcPlayerBuilder::OrcPlayerBuilder(std::string nickname) : PlayerBuilder(nickname) { }

void OrcPlayerBuilder::buildRace() { race_ = ORCS; }

void OrcPlayerBuilder::buildFactory() { factory_ = std::make_shared<OrcUnitFactory>(); }


PlayerDirector::PlayerDirector() : builder_(nullptr) { }

PlayerDirector::PlayerDirector(std::shared_ptr<PlayerBuilder> builder) : builder_(builder) { }

void PlayerDirector::setBuilder(std::shared_ptr<PlayerBuilder> builder) { builder_ = builder; }

std::shared_ptr<Player> PlayerDirector::buildPlayer() {
    builder_->buildRace();
    builder_->buildFactory();
    return builder_->getPlayer();
}
