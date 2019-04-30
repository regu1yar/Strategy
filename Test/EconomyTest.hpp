//
// Created by Роман Климовицкий on 25/04/2018.
//

#ifndef EconomyTest_hpp
#define EconomyTest_hpp

#include <gtest/gtest.h>
#include "Game_Process/Economy.hpp"
#include "Game_Process/UnitCost.hpp"
#include "Game_Process/EconomyUnitFactory.hpp"
#include "Units/Unit.hpp"


class UnitCostTest : public ::testing::Test {
protected:
    void SetUp() {
        std::cout << "UNIT COST TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "UNIT COST TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(UnitCostTest, RightCosts) {
    EXPECT_EQ(UnitCostSingleton::costs()->getCost(HUMANS + CREATURE + ARCHER), 120);
    EXPECT_EQ(UnitCostSingleton::costs()->getCost(ORCS + BUILDING + TOWN_HALL), 400);
    EXPECT_EQ(UnitCostSingleton::costs()->getCost(300), static_cast<size_t>(-1));

    std::cout << "COSTS TEST PASSED" << std::endl;
}

TEST_F(UnitCostTest, CostChangeTest) {
    size_t unitId = HUMANS + CREATURE + ARCHER;
    size_t oldCost = UnitCostSingleton::costs()->getCost(unitId);
    UnitCostSingleton::costs()->setNewCost(unitId, 200);
    EXPECT_EQ(UnitCostSingleton::costs()->getCost(unitId), 200);
    UnitCostSingleton::costs()->setNewCost(unitId, oldCost);
    EXPECT_EQ(UnitCostSingleton::costs()->getCost(unitId), oldCost);

    std::cout << "COSTS CHANGE TEST PASSED" << std::endl;
}


class EconomyTest : public ::testing::Test {
protected:
    std::shared_ptr<IEconomy> economy_;

    void SetUp() {
        economy_ = std::make_shared<Economy>();
        std::cout << "ECONOMY COST TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "ECONOMY COST TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(EconomyTest, TransactionTest) {
    EXPECT_EQ(economy_->getGold(), Economy::startGold);
    EXPECT_EQ(economy_->expense(Economy::startGold + 1), false);
    EXPECT_EQ(economy_->expense(Economy::startGold - 1), true);
    EXPECT_EQ(economy_->getGold(), 1);
    economy_->income(100);
    EXPECT_EQ(economy_->getGold(), 101);

    std::cout << "ECONOMY TEST PASSED" << std::endl;
}

class EconomyUnitFactoryDecoratorTest : public ::testing::Test {
protected:
    std::shared_ptr<UnitFactory> factory_;

    void SetUp() {
        factory_ = std::make_shared<HumanUnitFactory>();
        std::cout << "ECONOMY FACTORY COST TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "ECONOMY FACTORY COST TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(EconomyUnitFactoryDecoratorTest, UnableProductionTest) {
    factory_ = std::make_shared<EconomyUnitFactoryDecorator>(factory_, HUMANS, std::make_shared<Economy>(50));
    EXPECT_EQ(factory_->getTownHall(0, 0), nullptr);

    std::cout << "ECONOMY FACTORY BAD PRODUCTION TEST PASSED" << std::endl;
}

TEST_F(EconomyUnitFactoryDecoratorTest, ProductionTest) {
    factory_ = std::make_shared<EconomyUnitFactoryDecorator>(factory_, HUMANS, std::make_shared<Economy>(2000));
    std::shared_ptr<Unit> unit;
    unit = factory_->getTownHall(0, 0);
    EXPECT_EQ(unit->getId(), HUMANS + BUILDING + TOWN_HALL);
    unit = factory_->getBarracks(0, 0);
    EXPECT_EQ(unit->getId(), HUMANS + BUILDING + BARRACKS);
    unit = factory_->getWorker(0, 0);
    EXPECT_EQ(unit->getId(), HUMANS + CREATURE + WORKER);
    unit = factory_->getHealer(0, 0);
    EXPECT_EQ(unit->getId(), HUMANS + CREATURE + HEALER);
    unit = factory_->getArcher(0, 0);
    EXPECT_EQ(unit->getId(), HUMANS + CREATURE + ARCHER);
    unit = factory_->getWarrior(0, 0);
    EXPECT_EQ(unit->getId(), HUMANS + CREATURE + WARRIOR);

    std::cout << "ECONOMY FACTORY TEST PASSED" << std::endl;
}


#endif /* EconomyTest_hpp */
