//
// Created by Роман Климовицкий on 21/04/2018.
//

#include <iostream>
#include "Map.hpp"
#include "Units/Unit.hpp"


const size_t Map::defaultXSize = 100;
const size_t Map::defaultYSize = 100;

Map::Map(size_t x,
         size_t y) : map_(std::vector<std::vector<std::shared_ptr<Unit>>>(x,
                                                                          std::vector<std::shared_ptr<Unit>>(y,
                                                                                                             nullptr)))
{ }

Map::~Map() { }

size_t Map::getXSize() const { return map_.size(); }

size_t Map::getYSize() const { return map_.empty() ? 0 : map_[0].size(); }

bool Map::isEngaged(size_t x, size_t y) const {
    if (x >= getXSize() || y >= getYSize())
        return true;
    return map_[x][y] != nullptr;
}

bool Map::set(size_t x, size_t y, const std::shared_ptr<Unit>& unit) {
    if (unit == nullptr)
        return false;
    for (size_t i = 0; i < unit->getSize().first; ++i)
        for (size_t j = 0; j < unit->getSize().second; ++j)
            if (isEngaged(x + i, y + j))
                return false;
    for (size_t i = 0; i < unit->getSize().first; ++i)
        for (size_t j = 0; j < unit->getSize().second; ++j) {
            map_[x + i][y + j] = unit;
        }
    return true;
}

std::pair<size_t, size_t> Map::findFree(size_t x, size_t y, const std::shared_ptr<Unit>& unit) {
    while (x < getXSize()) {
        while (y < getYSize()) {
            if (set(x, y, unit))
                return { x, y };
            ++y;
        }
        y = 0;
        ++x;
    }
    return { x, y };
}

void Map::remove(const std::shared_ptr<Unit>& unit) {
    for (size_t i = 0; i < unit->getSize().first; ++i)
        for (size_t j = 0; j < unit->getSize().second; ++j)
            map_[unit->getPosition().first + i][unit->getPosition().second + j] = nullptr;
}

bool Map::moveTo(size_t x, size_t y, const std::shared_ptr<Unit>& unit) {
    if (set(x, y, unit)) {
        remove(unit);
        return true;
    } else
        return false;
}

std::shared_ptr<Unit> Map::getUnit(size_t x, size_t y) const {
    if (x >= getXSize() || y >= getYSize())
        return nullptr;
    return map_[x][y];
}

void Map::clear() {
    for (size_t i = 0; i < getXSize(); ++i)
        for (size_t j = 0; j < getYSize(); ++j) {
            map_[i][j] = nullptr;
        }
}