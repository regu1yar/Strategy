//
//  Player.cpp
//  
//
//  Created by Роман Климовицкий on 18.03.2018.
//

#include "Player/Player.hpp"


int Player::curXStartPosition_ = 0;
int Player::curYStartPosition_ = 0;

Player::Player(std::string nickname, Race race, std::shared_ptr<UnitFactory> factory,
               int x, int y) :
nickname_(nickname), race_(race), factory_(factory),
xStartPosition_(x), yStartPosition_(y) {
    std::shared_ptr<TownHall> townHall = factory_->getTownHall(xStartPosition_, yStartPosition_);
    units_[townHall->getUniqueId()] = townHall;
    for (size_t i = 1; i < Utils::startTownHalls_; ++i) {
        townHall = factory_->getTownHall(xStartPosition_ +
                                         i * townHall->getSize().first, yStartPosition_);
        units_[townHall->getUniqueId()] = townHall;
    }
    
    std::shared_ptr<Worker> worker =
    factory_->getWorker(xStartPosition_, yStartPosition_ + townHall->getSize().second);
    units_[worker->getUniqueId()] = worker;
    for (size_t i = 1; i < Utils::startWorkers_; ++i) {
        std::shared_ptr<Worker> worker =
        factory_->getWorker(xStartPosition_ + i * worker->getSize().first, yStartPosition_ + townHall->getSize().second);
        units_[worker->getUniqueId()] = worker;
    }
    
    if (x == curXStartPosition_)
        curXStartPosition_ += Utils::xStartPositionShift_;
    if (y == curYStartPosition_)
        curYStartPosition_ += Utils::yStartPositionShift_;
}

std::string Player::getNickname() const { return nickname_; }

Race Player::getRace() const { return race_; }

std::pair<int, int> Player::getStartPosition() const {
    return {xStartPosition_, yStartPosition_};
}

size_t Player::getUnitsNumber() const { return units_.size(); }

std::pair<int, int> Player::getCurStartPosition() { return {curXStartPosition_,
    curYStartPosition_}; }
