//
// Created by Роман Климовицкий on 21/04/2018.
//

#ifndef Map_hpp
#define Map_hpp

#include <vector>


class Unit;

class IMap {
public:
    virtual size_t getXSize() const = 0;
    virtual size_t getYSize() const = 0;

    virtual bool isEngaged(size_t x, size_t y) const = 0;
    virtual bool set(size_t x, size_t y, const std::shared_ptr<Unit>& unit) = 0;
    virtual std::pair<size_t, size_t> findFree(size_t x, size_t y, const std::shared_ptr<Unit>& unit) = 0;
    virtual void remove(const std::shared_ptr<Unit>& unit) = 0;
    virtual bool moveTo(size_t x, size_t y, const std::shared_ptr<Unit>& unit) = 0;

    virtual void clear() = 0;

    virtual ~IMap() { }
};


class Map : public IMap {
private:
    std::vector<std::vector<std::shared_ptr<Unit>>> map_;

public:
    static const size_t defaultXSize;
    static const size_t defaultYSize;

    explicit Map(size_t x = defaultXSize, size_t y = defaultYSize);
    ~Map();

    virtual size_t getXSize() const;
    virtual size_t getYSize() const;

    virtual bool isEngaged(size_t x, size_t y) const;
    virtual bool set(size_t x, size_t y, const std::shared_ptr<Unit>& unit);
    virtual std::pair<size_t, size_t> findFree(size_t x, size_t y, const std::shared_ptr<Unit>& unit);
    virtual void remove(const std::shared_ptr<Unit>& unit);
    virtual bool moveTo(size_t x, size_t y, const std::shared_ptr<Unit>& unit);

    virtual void clear();
};


#endif /* Map_hpp */
