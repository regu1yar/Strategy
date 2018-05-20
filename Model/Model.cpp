//
// Created by Роман Климовицкий on 19/05/2018.
//

#include "Model.hpp"
#include "Presenter/Subscriber.hpp"


Model::Model(size_t xSize, size_t ySize) :
        playerDirector_(std::make_shared<PlayerDirector>()), map_(std::make_shared<Map>(xSize, ySize)) { }

std::string Model::addPlayer(const std::string &playerNickname,
                                    const std::shared_ptr<Subscriber> subscriber, size_t race) {
    if (players_.find(playerNickname) != players_.end()) {
        switch (race) {
            case HUMANS:
                playerDirector_->setBuilder(std::make_shared<HumanPlayerBuilder>(playerNickname, map_));
                break;
            case ORCS:
                playerDirector_->setBuilder(std::make_shared<OrcPlayerBuilder>(playerNickname, map_));
                break;
            default:
                return "Wrong race. Please, try again!";
        }
        players_[playerNickname] = playerDirector_->buildPlayer();
        subscribers_[playerNickname] = subscriber;
        armies_[playerNickname] = std::vector<std::shared_ptr<Army>>();
        return "";
    } else {
        return "This nickname is engaged. Please, try again!";
    }
}

void Model::removePlayer(const std::string& playerNickname) {
    if (players_.find(playerNickname) == players_.end())
        return;
    armies_.erase(armies_.find(playerNickname));
    subscribers_.erase(subscribers_.find(playerNickname));
    players_.erase(players_.find(playerNickname));
}

void Model::update() const {
    for (auto iter = subscribers_.begin(); iter != subscribers_.end(); ++iter) {
        (*iter).second->update(shared_from_this());
    }
}

void Model::attack(const std::string &playerNickname, size_t armyNumber,
                   const std::pair<size_t, size_t> &targetPosition) {
    if (players_.find(playerNickname) == players_.end() ||
        armyNumber >= armies_[playerNickname].size() ||
        map_->getUnit(targetPosition.first, targetPosition.second) == nullptr)
        return;
    armies_[playerNickname][armyNumber]->attack(map_->getUnit(targetPosition.first, targetPosition.second));
    update();
}

void Model::heal(const std::string &playerNickname, size_t armyNumber,
                 const std::pair<size_t, size_t> &targetPosition) {
//    if (players_.find(playerNickname) == players_.end() ||
//        armyNumber >= armies_[playerNickname].size() ||
//        std::dynamic_pointer_cast<Creature>(map_->getUnit(targetPosition.first, targetPosition.second)) == nullptr)
//        return;
//    armies_[playerNickname][armyNumber]->heal(map_->getUnit(targetPosition.first, targetPosition.second));
//    update();
}

void Model::build(const std::string &playerNickname, const std::pair<size_t, size_t> &workerPosition,
                  const std::pair<size_t, size_t> &buildingPosition, size_t buildingType_) {
//    if (players_.find(playerNickname) == players_.end() ||
//        std::dynamic_pointer_cast<Worker>(map_->getUnit(workerPosition.first, workerPosition.second)) == nullptr ||
//        map_->getUnit(buildingPosition.first, buildingPosition.second) != nullptr)
//        return;
//    switch (buildingType_) {
//        case TOWN_HALL:
//            map_->getUnit(workerPosition.first,
//                          workerPosition.second)
//                    ->buildTownHall(buildingPosition.first, buildingPosition.second);
//    }

}
