//
//  UnitsTest.hpp
//  
//
//  Created by Роман Климовицкий on 19.03.2018.
//

#ifndef UnitsTest_hpp
#define UnitsTest_hpp

TEST_F(PlayerTest, StartUnitsTest) {
    std::string nickname = "Nickname";
    PlayerBuilder* builder = new OrcPlayerBuilder(nickname);
    director.setBuilder(builder);
    std::shared_ptr<Player> player = director.buildPlayer();
    EXPECT_EQ(Utils::startWorkers_ + Utils::startTownHalls_, player->getUnitsNumber());
    delete builder;
}


class HumanUnitsTest : public ::testing::Test {
protected:
    std::shared_ptr<Player> player;
    
    void SetUp() {
        std::cout << "HUMAN UNITS TEST SET UP" << std::endl;
    }
    
    void TearDown() {
        std::cout << "HUMAN UNITS TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(HumanUnitsTest)

#endif /* UnitsTest_hpp */
