//
// Created by Роман Климовицкий on 19/05/2018.
//

#ifndef MYSTRATEGY_PRESENTER_HPP
#define MYSTRATEGY_PRESENTER_HPP

#include <memory>
#include <string>
#include "Subscriber.hpp"
#include "Model/Model.hpp"

class Command;


class Presenter : public Subscriber {
private:
    std::shared_ptr<Model> mainModel_;
    std::shared_ptr<Command> command_;
    std::string playerNickname_;

public:
    Presenter(const std::shared_ptr<Model>& model) :
            mainModel_(model), command_(nullptr), playerNickname_("Default") { }

    void run();
    bool setNickname();
    bool handleCommand();
    virtual void update();
};


#endif //MYSTRATEGY_PRESENTER_HPP
