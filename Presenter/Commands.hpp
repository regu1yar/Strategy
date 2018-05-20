//
// Created by Роман Климовицкий on 19/05/2018.
//

#ifndef MYSTRATEGY_COMMANDS_HPP
#define MYSTRATEGY_COMMANDS_HPP


#include <cstddef>
#include <utility>
#include <string>
#include "Model/Model.hpp"


class Presenter;


class Command {
public:
    virtual void execute() = 0;

    virtual ~Command() { }
};


class TerminateCommand : public Command {
private:
    std::string playerNickname_;
    std::shared_ptr<Model> model_;

public:
    TerminateCommand(const std::string& playerNickname, const std::shared_ptr<Model>& model) :
            playerNickname_(playerNickname), model_(model) { }

    virtual void execute();

    ~TerminateCommand() { }
};

class ConnectionCommand : public Command {
private:
    std::string playerNickname_;
    std::shared_ptr<Model> model_;
    std::shared_ptr<Presenter> presenter_;
    size_t race_;

public:
    ConnectionCommand(const std::string& playerNickname, const std::shared_ptr<Model>& model,
                      const std::shared_ptr<Presenter>& presenter, size_t race) :
            playerNickname_(playerNickname), model_(model), presenter_(presenter), race_(race) { }

    virtual void execute();

    ~ConnectionCommand() { }
};

class NewGameCommand : public Command {
private:
    std::string playerNickname_;
    std::shared_ptr<Model> model_;

public:
    NewGameCommand(const std::string& playerNickname, const std::shared_ptr<Model>& model) :
            playerNickname_(playerNickname), model_(model) { }

    virtual void execute();

    ~NewGameCommand() { }
};

class AddArmyCommand : public Command {
private:
    std::string playerNickname_;
    std::shared_ptr<Model> model_;
    std::vector<std::pair<size_t, size_t>> units_;
    std::vector<size_t> armies_;

public:
    AddArmyCommand(const std::string& playerNickname, const std::shared_ptr<Model>& model,
                   const std::vector<std::pair<size_t, size_t>>& units,
                   const std::vector<size_t>& armies) :
            playerNickname_(playerNickname), model_(model),
            units_(units), armies_(armies) { }

    virtual void execute();

    ~AddArmyCommand() { }
};

class AttackCommand : public Command {
private:
    std::string playerNickname_;
    std::shared_ptr<Model> model_;
    size_t armyNumber_;
    std::pair<size_t, size_t> targetPosition_;

public:
    AttackCommand(const std::string& playerNickname, const std::shared_ptr<Model>& model,
                  size_t armyNumber, size_t targetXPosition, size_t targetYPosition) :
            playerNickname_(playerNickname), model_(model), armyNumber_(armyNumber),
            targetPosition_({targetXPosition, targetYPosition}) { }

    virtual void execute();

    ~AttackCommand() { }
};

class HealCommand : public Command {
private:
    std::string playerNickname_;
    std::shared_ptr<Model> model_;
    size_t armyNumber_;
    std::pair<size_t, size_t> targetPosition_;

public:
    HealCommand(const std::string& playerNickname, const std::shared_ptr<Model>& model,
                size_t armyNumber, size_t targetXPosition, size_t targetYPosition) :
            playerNickname_(playerNickname), model_(model), armyNumber_(armyNumber),
            targetPosition_({targetXPosition, targetYPosition}) { }

    virtual void execute();

    ~HealCommand() { }
};

class BuildCommand : public Command {
private:
    std::string playerNickname_;
    std::shared_ptr<Model> model_;
    std::pair<size_t, size_t> workerPosition_;
    std::pair<size_t, size_t> buildingPosition_;
    size_t buildingType_;

public:
    BuildCommand(const std::string& playerNickname, const std::shared_ptr<Model>& model,
                 size_t workerXPosition, size_t workerYPosition,
                 size_t buildingXPosition, size_t buildingYPosition,
                 size_t buildingType) : playerNickname_(playerNickname), model_(model),
                                        workerPosition_({workerXPosition, workerYPosition}),
                                        buildingPosition_({buildingXPosition, buildingYPosition}),
                                        buildingType_(buildingType) { }

    virtual void execute();

    ~BuildCommand() { }
};

class MoveCommand : public Command {
private:
    std::string playerNickname_;
    std::shared_ptr<Model> model_;
    size_t armyNumber_;
    std::pair<size_t, size_t> destinationPosition_;

public:
    MoveCommand(const std::string& playerNickname, const std::shared_ptr<Model>& model,
                size_t armyNumber, size_t destinationXPosition_, size_t destinationYPosition_) :
            playerNickname_(playerNickname), model_(model), armyNumber_(armyNumber),
            destinationPosition_({destinationXPosition_, destinationYPosition_}) { }

    virtual void execute();

    ~MoveCommand() { }
};


#endif //MYSTRATEGY_COMMANDS_HPP
