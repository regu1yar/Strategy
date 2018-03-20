//
//  UnitsTest.hpp
//  
//
//  Created by Роман Климовицкий on 19.03.2018.
//

#ifndef UnitsTest_hpp
#define UnitsTest_hpp

#include <gtest/gtest.h>
#include "Units/HumanUnits.hpp"
#include "Units/HumanUnitFactory.hpp"
#include "Utils/Utils.hpp"


class HumanUnitsTest : public ::testing::Test {
protected:
    std::shared_ptr<HumanUnitFactory> factory;

    static size_t unitCounter;
    static int defaultXPos;
    static int defaultYPos;
    
    void SetUp() {
        factory = std::make_shared<HumanUnitFactory>();
        std::cout << "HUMAN UNITS TEST SET UP" << std::endl;
    }
    
    void TearDown() {
        std::cout << "HUMAN UNITS TEST TEARED DOWN" << std::endl;
    }

    template<typename Func>
    std::shared_ptr<Unit> getUnit(Func func) {
        ++unitCounter;
        return func();
    }

    template<class CUnit>
    void testUnitConstruction(std::shared_ptr<Unit> unit) {
//        EXPECT_EQ(unit->getUniqueId(), unitCounter);
        EXPECT_EQ(unit->getId(), CUnit::id);
        EXPECT_EQ(unit->getName(), CUnit::name);
        EXPECT_EQ(unit->getSize().first, CUnit::xSize);
        EXPECT_EQ(unit->getSize().second, CUnit::ySize);
        EXPECT_EQ(unit->getPosition().first, defaultXPos);
        EXPECT_EQ(unit->getPosition().second, defaultYPos);
        EXPECT_EQ(unit->getMaxHealth(), CUnit::startHealth);
        EXPECT_EQ(unit->getHealth(), CUnit::startHealth);
        EXPECT_EQ(unit->getArmor(), CUnit::startArmor);
    }

    template<class CCreature>
    void testCreatureConstruction(std::shared_ptr<Creature> creature) {
        EXPECT_EQ(creature->getDamage(), CCreature::startDamage);
        EXPECT_EQ(creature->getRange(), CCreature::startRange);
    }
};

size_t HumanUnitsTest::unitCounter = -1;
int HumanUnitsTest::defaultXPos = 0;
int HumanUnitsTest::defaultYPos = 0;

TEST_F(HumanUnitsTest, TownHallConstructing) {
    std::shared_ptr<Unit> townHall = getUnit([this]() {
        return factory->getTownHall(defaultXPos, defaultYPos);
    });
    testUnitConstruction<HumanTownHall>(townHall);
    std::cout << "TOWN HALL CONSTRUCTING TEST PASSED" << std::endl;
}

TEST_F(HumanUnitsTest, BarracksConstructing) {
    std::shared_ptr<Unit> barracks = getUnit([this]() {
        return factory->getBarracks(defaultXPos, defaultYPos);
    });
    testUnitConstruction<HumanBarracks>(barracks);
    std::cout << "BARRACKS CONSTRUCTING TEST PASSED" << std::endl;
}

TEST_F(HumanUnitsTest, WorkerConstruction) {
    std::shared_ptr<Unit> worker = getUnit([this]() {
        return factory->getWorker(defaultXPos, defaultYPos);
    });
    testUnitConstruction<HumanWorker>(worker);
    testCreatureConstruction<HumanWorker>(std::dynamic_pointer_cast<Creature>(worker));
    std::cout << "WORKER CONSTRUCTING TEST PASSED" << std::endl;
}

TEST_F(HumanUnitsTest, WarriorConstruction) {
    std::shared_ptr<Unit> warrior = getUnit([this]() {
        return factory->getWarrior(defaultXPos, defaultYPos);
    });
    testUnitConstruction<HumanWarrior>(warrior);
    testCreatureConstruction<HumanWarrior>(std::dynamic_pointer_cast<Creature>(warrior));
    std::cout << "WARRIOR CONSTRUCTING TEST PASSED" << std::endl;
}

TEST_F(HumanUnitsTest, ArcherConstructing) {
    std::shared_ptr<Unit> archer = getUnit([this]() {
        return factory->getArcher(defaultXPos, defaultYPos);
    });
    testUnitConstruction<HumanArcher>(archer);
    testCreatureConstruction<HumanArcher>(std::dynamic_pointer_cast<Creature>(archer));
    std::cout << "ARCHER CONSTRUCTING TEST PASSED" << std::endl;
}

TEST_F(HumanUnitsTest, HealerConstructing) {
    std::shared_ptr<Unit> healer = getUnit([this]() {
        return factory->getHealer(defaultXPos, defaultYPos);
    });
    testUnitConstruction<HumanHealer>(healer);
    testCreatureConstruction<HumanHealer>(std::dynamic_pointer_cast<Creature>(healer));
    std::cout << "HEALER CONSTRUCTING TEST PASSED" << std::endl;
}


#endif /* UnitsTest_hpp */
