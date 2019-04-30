//
// Created by Роман Климовицкий on 26/04/2018.
//

#ifndef MapTest_hpp
#define MapTest_hpp

#include <gtest/gtest.h>
#include <iostream>
#include "Map/Map.hpp"
#include "Units/HumanUnits.hpp"


class MapTest : public ::testing::Test {
protected:
    std::shared_ptr<IMap> map_;

    void SetUp() {
        map_ = std::make_shared<Map>();

        std::cout << "MAP TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "MAP TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(MapTest, MapConstructingTest) {
    EXPECT_EQ(map_->getXSize(), Map::defaultXSize);
    EXPECT_EQ(map_->getYSize(), Map::defaultYSize);

    map_ = std::make_shared<Map>(150, 150);
    EXPECT_EQ(map_->getXSize(), 150);
    EXPECT_EQ(map_->getYSize(), 150);

    std::cout << "MAP CONSTRUCTING TEST PASSED" << std::endl;
}

TEST_F(MapTest, MapSetTest) {
    std::shared_ptr<Unit> unit = std::make_shared<HumanWorker>(std::make_shared<HumanUnitFactory>(),
                                                               std::make_shared<Map>(), 0, 0);
    EXPECT_EQ(map_->set(0, 0, unit), false);
    EXPECT_EQ(map_->isEngaged(0, 0), false);
    EXPECT_EQ(map_->getUnit(0, 0), nullptr);

    unit = std::make_shared<HumanWorker>(std::make_shared<HumanUnitFactory>(),
                                         map_, 0, 0);
    EXPECT_EQ(map_->set(0, 0, unit), true);
    EXPECT_EQ(map_->isEngaged(0, 0), true);
    EXPECT_EQ(map_->getUnit(0, 0), unit);

    std::shared_ptr<Unit> unit1 = std::make_shared<HumanTownHall>(std::make_shared<HumanUnitFactory>(),
                                           map_, 0, 0);
    EXPECT_EQ(map_->set(0, 0, unit1), false);

    unit1 = std::make_shared<HumanTownHall>(std::make_shared<HumanUnitFactory>(),
                                            map_, 1, 1);
    EXPECT_EQ(map_->set(1, 1, unit1), true);

    EXPECT_EQ(map_->getUnit(unit1->getPosition().first, unit1->getPosition().second), unit1);
    EXPECT_EQ(map_->getUnit(unit1->getPosition().first + 1, unit1->getPosition().second + 1), unit1);

    std::cout << "MAP SET TEST PASSED" << std::endl;
}


#endif /* MapTest_hpp */
