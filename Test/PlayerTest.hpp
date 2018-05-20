//
//  PlayerTest.hpp
//  
//
//  Created by Роман Климовицкий on 18.03.2018.
//

#ifndef Test_hpp
#define Test_hpp

#include <string>
#include <memory>
#include <gtest/gtest.h>
#include <iostream>
#include "Player/PlayerDirector.hpp"
#include "Units/HumanUnitFactory.hpp"
#include "Units/OrcUnitFactory.hpp"
#include "Utils/Utils.hpp"


class PlayerTest : public ::testing::Test {
protected:
    PlayerDirector director;
    
    void SetUp() {
        std::cout << "PLAYER TEST SET UP" << std::endl;
    }
    
    void TearDown() {
        std::cout << "PLAYER TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(PlayerTest, HumanNicknameTest) {
    std::string nickname = "Nickname";
    std::shared_ptr<HumanPlayerBuilder> builder = std::make_shared<HumanPlayerBuilder>(nickname);
    director.setBuilder(builder);
    std::shared_ptr<Player> player = director.buildPlayer();
    EXPECT_EQ(nickname, player->getNickname());

    std::cout << "HUMAN NICKNAME TEST PASSED" << std::endl;
}

TEST_F(PlayerTest, OrcNicknameTest) {
    std::string nickname = "Nickname";
    std::shared_ptr<OrcPlayerBuilder> builder = std::make_shared<OrcPlayerBuilder>(nickname);
    director.setBuilder(builder);
    std::shared_ptr<Player> player = director.buildPlayer();
    EXPECT_EQ(nickname, player->getNickname());

    std::cout << "ORC NICKNAME TEST PASSED" << std::endl;
}

TEST_F(PlayerTest, HumanRaceTest) {
    Race race = HUMANS;
    std::string nickname = "Nickname";
    std::shared_ptr<HumanPlayerBuilder> builder = std::make_shared<HumanPlayerBuilder>(nickname);
    director.setBuilder(builder);
    std::shared_ptr<Player> player = director.buildPlayer();
    EXPECT_EQ(race, player->getRace());

    std::cout << "HUMAN RACE TEST PASSED" << std::endl;
}

TEST_F(PlayerTest, OrcRaceTest) {
    Race race = ORCS;
    std::string nickname = "Nickname";
    std::shared_ptr<OrcPlayerBuilder> builder = std::make_shared<OrcPlayerBuilder>(nickname);
    director.setBuilder(builder);
    std::shared_ptr<Player> player = director.buildPlayer();
    EXPECT_EQ(race, player->getRace());

    std::cout << "ORC RACE TEST PASSED" << std::endl;
}

TEST_F(PlayerTest, DefaultPositionTest) {
    std::string nickname = "Nickname";
    size_t curX = Player::getCurStartPosition().first;
    size_t curY = Player::getCurStartPosition().second;
    std::shared_ptr<HumanPlayerBuilder> builder = std::make_shared<HumanPlayerBuilder>(nickname);
    director.setBuilder(builder);
    std::shared_ptr<Player> player;
    for (size_t i = 0; i < 100; ++i) {
        player = director.buildPlayer();
        EXPECT_EQ(curX + i * Player::xStartPositionShift_, player->getStartPosition().first);
        EXPECT_EQ(curY + i * Player::yStartPositionShift_, player->getStartPosition().second);
    }

    std::cout << "DEFAULT POSITION TEST PASSED" << std::endl;
}

TEST_F(PlayerTest, StartUnitsTest) {
    std::string nickname = "Nickname";
    std::shared_ptr<OrcPlayerBuilder> builder = std::make_shared<OrcPlayerBuilder>(nickname);
    director.setBuilder(builder);
    std::shared_ptr<Player> player = director.buildPlayer();

    std::cout << "START UNITS TEST PASSED" << std::endl;
}



#endif /* PlayerTest_hpp */
