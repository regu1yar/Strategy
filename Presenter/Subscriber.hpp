//
// Created by Роман Климовицкий on 19/05/2018.
//

#ifndef MYSTRATEGY_SUBSCRIBER_HPP
#define MYSTRATEGY_SUBSCRIBER_HPP

#include <memory>
#include "Model/Model.hpp"


class Subscriber : public std::enable_shared_from_this<Subscriber> {
public:
    virtual void update(const std::shared_ptr<const Model>& model) = 0;

    virtual ~Subscriber() { }
};


#endif //MYSTRATEGY_SUBSCRIBER_HPP
