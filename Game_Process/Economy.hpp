//
// Created by Роман Климовицкий on 21/04/2018.
//

#ifndef Economy_hpp
#define Economy_hpp

#include <cstdlib>


class IEconomy {
public:
    virtual int getGold() const = 0;

    virtual bool expense(size_t amount) = 0;
    virtual void income(size_t amount) = 0;
};


class Economy : public IEconomy {
private:
    int gold_;

public:
    static const int startGold;

    explicit Economy(int gold = startGold);

    virtual int getGold() const;

    virtual bool expense(size_t amount);
    virtual void income(size_t amount);
};


#endif /* Economy_hpp */
