//
// Created by Роман Климовицкий on 21/04/2018.
//

#include "Army.hpp"


CompositeArmy::CompositeArmy() : x_(0), y_(0), size_(0) { }

CompositeArmy::CompositeArmy(const CompositeArmy &compositeArmy) :
        x_(compositeArmy.x_), y_(compositeArmy.y_), size_(compositeArmy.size_), army_(compositeArmy.army_) { }

CompositeArmy& CompositeArmy::operator=(const CompositeArmy &compositeArmy) {
    if(this == &compositeArmy)
        return *this;
    x_ = compositeArmy.x_;
    y_ = compositeArmy.y_;
    size_ = compositeArmy.size_;
    army_ = compositeArmy.army_;
    return *this;
}

CompositeArmy::~CompositeArmy() { army_.clear(); }

size_t CompositeArmy::getSize() const { return size_; }

std::pair<size_t, size_t> CompositeArmy::getPosition() const { return { x_, y_ }; }

std::pair<size_t, size_t> CompositeArmy::calculateAveragePositionAfterAdding(const std::shared_ptr<Army>& army1,
                                                                             const std::shared_ptr<Army>& army2) {
    std::pair<size_t, size_t> pos1 = army1->getPosition();
    std::pair<size_t, size_t> pos2 = army2->getPosition();

    size_t x = (pos1.first * army1->getSize() + pos2.first * army2->getSize()) / (army1->getSize() + army2->getSize());
    size_t y = (pos1.second * army1->getSize() + pos2.second * army2->getSize()) / (army1->getSize() + army2->getSize());

    return { x, y };
}

std::pair<size_t, size_t> CompositeArmy::calculateAveragePositionAfterRemoving(const std::shared_ptr<Army>& army1,
                                                                               const std::shared_ptr<Army>& army2) {
    std::pair<size_t, size_t> pos1 = army1->getPosition();
    std::pair<size_t, size_t> pos2 = army2->getPosition();

    size_t x = (pos1.first * army1->getSize() - pos2.first * army2->getSize()) / (army1->getSize() - army2->getSize());
    size_t y = (pos1.second * army1->getSize() - pos2.second * army2->getSize()) / (army1->getSize() - army2->getSize());

    return { x, y };
}

void CompositeArmy::moveBy(int x, int y) {
    x_ += x;
    y_ += y;
    for (auto iter = army_.begin(); iter != army_.end(); ++iter) {
        (*iter)->moveBy(x, y);
    }
}

void CompositeArmy::add(const std::shared_ptr<Army>& army) {
    if (shared_from_this() == army || army_.find(army) != army_.end())
        return;
    std::pair<size_t, size_t> newPos = calculateAveragePositionAfterAdding(shared_from_this(), army);
    x_ = newPos.first;
    y_ = newPos.second;
    size_ += army->getSize();
    army_.insert(army);
}

void CompositeArmy::add(const std::shared_ptr<Creature>& unit) {
    add(std::make_shared<CertainUnit<Creature>>(unit));
}

void CompositeArmy::remove(const std::shared_ptr<Army>& army) {
    auto iter = army_.find(army);
    if (iter != army_.end()) {
        std::pair<size_t, size_t> newPos = calculateAveragePositionAfterRemoving(shared_from_this(), army);
        x_ = newPos.first;
        y_ = newPos.second;
        size_ -= army->getSize();
        army_.erase(iter);
    }
}

void CompositeArmy::moveTo(size_t x, size_t y) {
    int xShift = x - x_;
    int yShift = y - y_;
    for (auto iter = army_.begin(); iter != army_.end(); ++iter) {
        (*iter)->moveBy(xShift, yShift);
    }
}

void CompositeArmy::attack(const std::shared_ptr<Unit>& target) {
    for (auto iter = army_.begin(); iter != army_.end(); ++iter) {
        (*iter)->attack(target);
    }
}

void CompositeArmy::heal(const std::shared_ptr<Creature>& target) {
    for (auto iter = army_.begin(); iter != army_.end(); ++iter) {
        (*iter)->heal(target);
    }
}


template<typename UnitT>
size_t CertainUnit<UnitT>::getSize() const { return 1; }

template<typename UnitT>
std::pair<size_t, size_t> CertainUnit<UnitT>::getPosition() const { return unit_->getPosition(); };

template<typename UnitT>
void CertainUnit<UnitT>::moveBy(int x, int y) { unit_->moveBy(x, y); }

template<typename UnitT>
void CertainUnit<UnitT>::moveTo(size_t x, size_t y) { unit_->moveTo(x, y); }

template<typename UnitT>
void CertainUnit<UnitT>::attack(const std::shared_ptr<Unit>& target) { unit_->attack(target); }

template<typename UnitT>
void CertainUnit<UnitT>::heal(const std::shared_ptr<Creature>& target) { }

template<>
void CertainUnit<Building>::moveBy(int x, int y) { }

template<>
void CertainUnit<Building>::moveTo(size_t x, size_t y) { }

template<>
void CertainUnit<Building>::attack(const std::shared_ptr<Unit>& target) { }

template<>
void CertainUnit<Building>::heal(const std::shared_ptr<Creature>& target) { }


template<>
void CertainUnit<Healer>::heal(const std::shared_ptr<Creature>& target) { unit_->heal(target); }