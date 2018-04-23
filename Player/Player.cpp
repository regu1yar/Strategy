//
//  Player.cpp
//  
//
//  Created by Роман Климовицкий on 18.03.2018.
//

#include "Units/HumanUnitFactory.hpp"
#include "Units/OrcUnitFactory.hpp"
#include "Player/Player.hpp"


const int Player::startWorkers_ = 5;
const int Player::startTownHalls_ = 1;
const int Player::xStartPositionShift_ = 20;
const int Player::yStartPositionShift_ = 20;

size_t Player::curXStartPosition_ = 0;
size_t Player::curYStartPosition_ = 0;

Player::Player(const std::string &nickname, Race race,
               const std::shared_ptr<IMap>& map, size_t x, size_t y) : nickname_(nickname), race_(race), map_(map),
                                                                       xStartPosition_(x), yStartPosition_(y) {
    switch (race_) {
        case HUMANS:
            factory_ = std::make_shared<HumanUnitFactory>(map_);
            break;
        case ORCS:
            factory_ = std::make_shared<OrcUnitFactory>(map_);
            break;
        default:
            break;
    }
    setStartResources();
    updateStartPositions();
}

void Player::setStartResources() {
    std::shared_ptr<TownHall> townHall = factory_->getTownHall(xStartPosition_, yStartPosition_);
    units_[townHall->getUniqueId()] = townHall;
    for (size_t i = 1; i < startTownHalls_; ++i) {
        townHall = factory_->getTownHall(xStartPosition_ + i * townHall->getSize().first, yStartPosition_);
        units_[townHall->getUniqueId()] = townHall;
    }

    std::shared_ptr<Worker> worker = factory_->getWorker(xStartPosition_, yStartPosition_ + townHall->getSize().second);
    units_[worker->getUniqueId()] = worker;
    for (size_t i = 1; i < startWorkers_; ++i) {
        worker = factory_->getWorker(xStartPosition_ + i * worker->getSize().first,
                                     yStartPosition_ + townHall->getSize().second);
        units_[worker->getUniqueId()] = worker;
    }
}

void Player::updateStartPositions() {
    if (xStartPosition_ == curXStartPosition_)
        curXStartPosition_ += xStartPositionShift_;
    if (yStartPosition_ == curYStartPosition_)
        curYStartPosition_ += yStartPositionShift_;
}

std::string Player::getNickname() const { return nickname_; }

Race Player::getRace() const { return race_; }

std::pair<size_t, size_t> Player::getStartPosition() const {
    return {xStartPosition_, yStartPosition_};
}

size_t Player::getUnitsNumber() const { return units_.size(); }

std::pair<size_t, size_t> Player::getCurStartPosition() { return {curXStartPosition_,
    curYStartPosition_}; }
