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
    PlayerBuilder* builder = new HumanPlayerBuilder(nickname);
    director.setBuilder(builder);
    std::shared_ptr<Player> player = director.buildPlayer();
    EXPECT_EQ(nickname, player->getNickname());
    delete builder;
}

TEST_F(PlayerTest, OrcNicknameTest) {
    std::string nickname = "Nickname";
    PlayerBuilder* builder = new OrcPlayerBuilder(nickname);
    director.setBuilder(builder);
    std::shared_ptr<Player> player = director.buildPlayer();
    EXPECT_EQ(nickname, player->getNickname());
    delete builder;
}

TEST_F(PlayerTest, HumanRaceTest) {
    Race race = HUMANS;
    std::string nickname = "Nickname";
    PlayerBuilder* builder = new HumanPlayerBuilder(nickname);
    director.setBuilder(builder);
    std::shared_ptr<Player> player = director.buildPlayer();
    EXPECT_EQ(race, player->getRace());
    delete builder;
}

TEST_F(PlayerTest, OrcRaceTest) {
    Race race = ORCS;
    std::string nickname = "Nickname";
    PlayerBuilder* builder = new OrcPlayerBuilder(nickname);
    director.setBuilder(builder);
    std::shared_ptr<Player> player = director.buildPlayer();
    EXPECT_EQ(race, player->getRace());
    delete builder;
}

TEST_F(PlayerTest, DefaultPositionTest) {
    std::string nickname = "Nickname";
    int curX = Player::getCurStartPosition().first;
    int curY = Player::getCurStartPosition().second;
    PlayerBuilder* builder = new HumanPlayerBuilder(nickname);
    director.setBuilder(builder);
    std::shared_ptr<Player> player;
    for (size_t i = 0; i < 100; ++i) {
        player = director.buildPlayer();
        EXPECT_EQ(curX + i * Utils::xStartPositionShift_, player->getStartPosition().first);
        EXPECT_EQ(curY + i * Utils::yStartPositionShift_, player->getStartPosition().second);
    }
    delete builder;
}


#endif /* PlayerTest_hpp */
