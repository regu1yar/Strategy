//
// Created by Роман Климовицкий on 23/04/2018.
//

#ifndef ArmyTest_hpp
#define ArmyTest_hpp

#include <gtest/gtest.h>
#include "Army/Army.hpp"
#include "Units/Unit.hpp"
#include "Units/HumanUnitFactory.hpp"


class ArmyTest : public ::testing::Test {
protected:
    std::shared_ptr<HumanUnitFactory> humanFactory;

    void SetUp() {
        humanFactory = std::make_shared<HumanUnitFactory>();
        std::cout << "ARMY TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "ARMY TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(ArmyTest, ConstructingTest) {
    std::shared_ptr<CompositeArmy> army = std::make_shared<CompositeArmy>();

    EXPECT_EQ(army->getSize(), 0);
    EXPECT_EQ(army->getPosition().first, 0);
    EXPECT_EQ(army->getPosition().second, 0);

    auto unit1 = humanFactory->getWarrior(0, 0);
    auto unit2 = humanFactory->getArcher(0, 2);

    army->add(unit2);
    EXPECT_EQ(army->getSize(), 1);
    EXPECT_EQ(army->getPosition().first, 0);
    EXPECT_EQ(army->getPosition().second, 2);

//    Currently adding the same army twice doesn't check
//    army->add(unit2);
//    EXPECT_EQ(army->getSize(), 1);
//    EXPECT_EQ(army->getPosition().first, 0);
//    EXPECT_EQ(army->getPosition().second, 2);

    army->add(unit1);
    EXPECT_EQ(army->getSize(), 2);
    EXPECT_EQ(army->getPosition().first, 0);
    EXPECT_EQ(army->getPosition().second, 1);

    std::shared_ptr<CompositeArmy> army1 = std::make_shared<CompositeArmy>();
    auto unit3 = humanFactory->getHealer(1, 1);
    army1->add(unit3);
    army->add(army1);
    EXPECT_EQ(army->getSize(), 3);
    EXPECT_EQ(army->getPosition().first, 0);
    EXPECT_EQ(army->getPosition().second, 1);
}

TEST_F(ArmyTest, AttackTest) {
    std::shared_ptr<CompositeArmy> army = std::make_shared<CompositeArmy>();

    auto unit1 = humanFactory->getWarrior(0, 0);
    auto unit2 = humanFactory->getArcher(0, 2);

    army->add(unit2);
    army->add(unit1);

    auto unit4 = humanFactory->getWorker(0, 1);

    EXPECT_EQ(unit1->getPosition().first, 0);
    EXPECT_EQ(unit1->getPosition().second, 0);
    EXPECT_EQ(unit2->getPosition().first, 0);
    EXPECT_EQ(unit2->getPosition().second, 2);
    EXPECT_EQ(unit4->getPosition().first, 0);
    EXPECT_EQ(unit4->getPosition().second, 1);

    army->attack(unit4);
//    EXPECT_EQ(unit4->getHealth() < unit4->getMaxHealth(), true);
}

TEST_F(ArmyTest, MoveTest) {
    std::shared_ptr<CompositeArmy> army = std::make_shared<CompositeArmy>();

    auto unit1 = humanFactory->getWarrior(0, 0);
    auto unit2 = humanFactory->getArcher(0, 2);

    army->add(unit2);
    army->add(unit1);

    army->moveBy(0, 1);
    EXPECT_EQ(army->getPosition().first, 0);
    EXPECT_EQ(army->getPosition().second, 2);
    EXPECT_EQ(unit1->getPosition().first, 0);
    EXPECT_EQ(unit1->getPosition().second, 1);
}


#endif /* ArmyTest_hpp */
