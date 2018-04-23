//
// Created by Роман Климовицкий on 21/04/2018.
//

#ifndef Army_hpp
#define Army_hpp

#include <set>
#include <memory>
#include "Units/Creature.hpp"
#include "Units/Building.hpp"
#include "Units/Creature.hpp"


class Army : public std::enable_shared_from_this<Army> {
public:
    virtual size_t getSize() const = 0;
    virtual std::pair<size_t, size_t> getPosition() const = 0;
    virtual void moveBy(int x, int y) = 0;
    virtual void moveTo(size_t x, size_t y) = 0;
    virtual void attack(const std::shared_ptr<Unit>& target) = 0;
    virtual void heal(const std::shared_ptr<Creature>& target) = 0;
};


template<typename UnitT>
class CertainUnit : public Army {
protected:
    std::shared_ptr<UnitT> unit_;

public:
    CertainUnit() : unit_(nullptr) { }

    template<typename UnitU>
    CertainUnit(const std::shared_ptr<UnitU>& unit) : unit_(unit) { }

    virtual size_t getSize() const;
    virtual std::pair<size_t, size_t> getPosition() const;
    virtual void moveBy(int x, int y);

    virtual void moveTo(size_t x, size_t y);
    virtual void attack(const std::shared_ptr<Unit>& target);
    virtual void heal(const std::shared_ptr<Creature>& target);
};


class CompositeArmy : public Army {
protected:
    size_t x_;
    size_t y_;
    size_t size_;
    std::set<std::shared_ptr<Army>> army_;

    static std::pair<size_t, size_t> calculateAveragePositionAfterAdding(const std::shared_ptr<Army>& army1,
                                                                         const std::shared_ptr<Army>& army2);
    static std::pair<size_t, size_t> calculateAveragePositionAfterRemoving(const std::shared_ptr<Army>& army1,
                                                                           const std::shared_ptr<Army>& army2);

public:
    CompositeArmy();
    CompositeArmy(const CompositeArmy& compositeArmy);
    CompositeArmy& operator=(const CompositeArmy& compositeArmy);

    ~CompositeArmy();

    virtual size_t getSize() const;
    virtual std::pair<size_t, size_t> getPosition() const;

    void add(const std::shared_ptr<Army>& army);
    void add(const std::shared_ptr<Creature>& unit);
    void remove(const std::shared_ptr<Army>& army);

    virtual void moveBy(int x, int y);
    virtual void moveTo(size_t x, size_t y);
    virtual void attack(const std::shared_ptr<Unit>& target);
    virtual void heal(const std::shared_ptr<Creature>& target);
};


#endif /* Army_hpp */
