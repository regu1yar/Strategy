//
// Created by Роман Климовицкий on 19/05/2018.
//

#ifndef MYSTRATEGY_MODEL_HPP
#define MYSTRATEGY_MODEL_HPP


#include <map>
#include "Map/Map.hpp"
#include "Player/PlayerDirector.hpp"
#include "Units/Creature.hpp"
#include "Army/Army.hpp"


class Subscriber;

class Model : public std::enable_shared_from_this<Model> {
private:
    std::shared_ptr<PlayerDirector> playerDirector_;
    std::shared_ptr<IMap> map_;
    std::map<std::string, std::shared_ptr<Player>> players_;
    std::map<std::string, std::shared_ptr<Subscriber>> subscribers_;
    std::map<std::string, std::vector<std::shared_ptr<Army>>> armies_;

public:
    Model(size_t xSize = Map::defaultXSize, size_t ySize = Map::defaultYSize);

    friend class Subscriber;

    std::string addPlayer(const std::string& playerNickname, const std::shared_ptr<Subscriber> subscriber, size_t race);
    void removePlayer(const std::string& playerNickname);
    void update() const;
    void attack(const std::string& playerNickname, size_t armyNumber,
                const std::pair<size_t, size_t>& targetPosition);
    void heal(const std::string& playerNickname, size_t armyNumber,
              const std::pair<size_t, size_t>& targetPosition);
    void build(const std::string& playerNickname,
               const std::pair<size_t, size_t>& workerPosition,
               const std::pair<size_t, size_t>& buildingPosition,
               size_t buildingType_);
    void move(const std::string& playerNickname, size_t armyNumber,
              const std::pair<size_t, size_t>& destinationPosition);
    void addArmy(const std::string& playerNickname,
                 const std::vector<std::pair<size_t, size_t>>& units,
                 const std::vector<size_t>& armies);
};


#endif //MYSTRATEGY_MODEL_HPP
