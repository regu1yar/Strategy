//
//  UnitsTest.hpp
//  
//
//  Created by Роман Климовицкий on 19.03.2018.
//

#ifndef UnitsTest_hpp
#define UnitsTest_hpp

#include <gtest/gtest.h>
#include <cmath>
#include <set>
#include "Units/HumanUnits.hpp"
#include "Units/HumanUnitFactory.hpp"
#include "Units/OrcUnits.hpp"
#include "Units/OrcUnitFactory.hpp"
#include "Utils/Utils.hpp"


class UnitsTest : public ::testing::Test {
protected:
    std::shared_ptr<HumanUnitFactory> humanFactory;
    std::shared_ptr<OrcUnitFactory> orcFactory;

    static size_t defaultXPos;
    static size_t defaultYPos;
    
    void SetUp() {
        humanFactory = std::make_shared<HumanUnitFactory>();
        orcFactory = std::make_shared<OrcUnitFactory>();
        Unit::setCounterToZero();
        std::cout << "UNITS TEST SET UP" << std::endl;
    }
    
    void TearDown() {
        std::cout << "UNITS TEST TEARED DOWN" << std::endl;
    }

    template<typename CUnit, typename Func>
    std::shared_ptr<CUnit> getUnit(Func func) {
        return func();
    }

    void checkId(std::set<size_t>& ids, const std::shared_ptr<Unit>& unit) {
        EXPECT_EQ(ids.find(unit->getUniqueId()), ids.end()) << unit->getUniqueId() << std::endl;
        ids.insert(unit->getUniqueId());
    }

    template<class CUnit>
    void testUnitConstruction(const std::shared_ptr<Unit>& unit) {
        EXPECT_EQ(unit->getId(), CUnit::id);
        EXPECT_EQ(unit->getName(), CUnit::name);
        EXPECT_EQ(unit->getSize().first, CUnit::xSize);
        EXPECT_EQ(unit->getSize().second, CUnit::ySize);
        EXPECT_EQ(unit->getPosition().first, defaultXPos);
        EXPECT_EQ(unit->getPosition().second, defaultYPos);
        EXPECT_EQ(unit->getMaxHealth(), CUnit::defaultStartHealth);
        EXPECT_EQ(unit->getHealth(), CUnit::defaultStartHealth);
        EXPECT_EQ(unit->getArmor(), CUnit::defaultStartArmor);
    }

    template<class CCreature>
    void testCreatureConstruction(const std::shared_ptr<Creature>& creature) {
        EXPECT_EQ(creature->getDamage(), CCreature::defaultStartDamage);
        EXPECT_EQ(creature->getAttackRange(), CCreature::defaultStartAttackRange);
        EXPECT_EQ(creature->getMoveRange(), CCreature::defaultStartMoveRange);
    }
};

size_t UnitsTest::defaultXPos = 0;
size_t UnitsTest::defaultYPos = 0;

TEST_F(UnitsTest, idUniqueness) {
    std::set<size_t> uniqueIds;
    std::shared_ptr<Unit> unit;

    unit = humanFactory->getTownHall(defaultXPos, defaultYPos);
    checkId(uniqueIds, unit);
    unit = humanFactory->getBarracks(defaultXPos, defaultYPos);
    checkId(uniqueIds, unit);
    unit = humanFactory->getWorker(defaultXPos, defaultYPos);
    checkId(uniqueIds, unit);
    unit = humanFactory->getWarrior(defaultXPos, defaultYPos);
    checkId(uniqueIds, unit);
    unit = humanFactory->getArcher(defaultXPos, defaultYPos);
    checkId(uniqueIds, unit);
    unit = humanFactory->getHealer(defaultXPos, defaultYPos);
    checkId(uniqueIds, unit);

    unit = orcFactory->getTownHall(defaultXPos, defaultYPos);
    checkId(uniqueIds, unit);
    unit = orcFactory->getBarracks(defaultXPos, defaultYPos);
    checkId(uniqueIds, unit);
    unit = orcFactory->getWorker(defaultXPos, defaultYPos);
    checkId(uniqueIds, unit);
    unit = orcFactory->getWarrior(defaultXPos, defaultYPos);
    checkId(uniqueIds, unit);
    unit = orcFactory->getArcher(defaultXPos, defaultYPos);
    checkId(uniqueIds, unit);
    unit = orcFactory->getHealer(defaultXPos, defaultYPos);
    checkId(uniqueIds, unit);

    std::cout << "ID UNIQUENESS TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, TownHallConstructing) {
    std::shared_ptr<Unit> humanTownHall = getUnit<Unit>([this]() {
        return humanFactory->getTownHall(defaultXPos, defaultYPos);
    });
    testUnitConstruction<HumanTownHall>(humanTownHall);

    std::cout << "HUMAN TOWN HALL CONSTRUCTING TEST PASSED" << std::endl;

    std::shared_ptr<Unit> orcTownHall = getUnit<Unit>([this]() {
        return orcFactory->getTownHall(defaultXPos, defaultYPos);
    });
    testUnitConstruction<OrcTownHall>(orcTownHall);

    std::cout << "ORC TOWN HALL CONSTRUCTING TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, BarracksConstructing) {
    std::shared_ptr<Unit> humanBarracks = getUnit<Unit>([this]() {
        return humanFactory->getBarracks(defaultXPos, defaultYPos);
    });
    testUnitConstruction<HumanBarracks>(humanBarracks);

    std::cout << "HUMAN BARRACKS CONSTRUCTING TEST PASSED" << std::endl;

    std::shared_ptr<Unit> orcBarracks = getUnit<Unit>([this]() {
        return orcFactory->getBarracks(defaultXPos, defaultYPos);
    });
    testUnitConstruction<OrcBarracks>(orcBarracks);

    std::cout << "ORC BARRACKS CONSTRUCTING TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, WorkerConstruction) {
    std::shared_ptr<Unit> humanWorker = getUnit<Unit>([this]() {
        return humanFactory->getWorker(defaultXPos, defaultYPos);
    });
    testUnitConstruction<HumanWorker>(humanWorker);
    testCreatureConstruction<HumanWorker>(std::dynamic_pointer_cast<Creature>(humanWorker));

    std::cout << "HUMAN WORKER CONSTRUCTING TEST PASSED" << std::endl;

    std::shared_ptr<Unit> orcWorker = getUnit<Unit>([this]() {
        return orcFactory->getWorker(defaultXPos, defaultYPos);
    });
    testUnitConstruction<OrcWorker>(orcWorker);
    testCreatureConstruction<OrcWorker>(std::dynamic_pointer_cast<Creature>(orcWorker));

    std::cout << "ORC WORKER CONSTRUCTING TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, WarriorConstruction) {
    std::shared_ptr<Unit> humanWarrior = getUnit<Unit>([this]() {
        return humanFactory->getWarrior(defaultXPos, defaultYPos);
    });
    testUnitConstruction<HumanWarrior>(humanWarrior);
    testCreatureConstruction<HumanWarrior>(std::dynamic_pointer_cast<Creature>(humanWarrior));

    std::cout << "HUMAN WARRIOR CONSTRUCTING TEST PASSED" << std::endl;

    std::shared_ptr<Unit> orcWarrior = getUnit<Unit>([this]() {
        return orcFactory->getWarrior(defaultXPos, defaultYPos);
    });
    testUnitConstruction<OrcWarrior>(orcWarrior);
    testCreatureConstruction<OrcWarrior>(std::dynamic_pointer_cast<Creature>(orcWarrior));

    std::cout << "ORC WARRIOR CONSTRUCTING TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, ArcherConstructing) {
    std::shared_ptr<Unit> humanArcher = getUnit<Unit>([this]() {
        return humanFactory->getArcher(defaultXPos, defaultYPos);
    });
    testUnitConstruction<HumanArcher>(humanArcher);
    testCreatureConstruction<HumanArcher>(std::dynamic_pointer_cast<Creature>(humanArcher));

    std::cout << "HUMAN ARCHER CONSTRUCTING TEST PASSED" << std::endl;

    std::shared_ptr<Unit> orcArcher = getUnit<Unit>([this]() {
        return orcFactory->getArcher(defaultXPos, defaultYPos);
    });
    testUnitConstruction<OrcArcher>(orcArcher);
    testCreatureConstruction<OrcArcher>(std::dynamic_pointer_cast<Creature>(orcArcher));

    std::cout << "ORC ARCHER CONSTRUCTING TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, HealerConstructing) {
    std::shared_ptr<Healer> humanHealer = getUnit<Healer>([this]() {
        return humanFactory->getHealer(defaultXPos, defaultYPos);
    });
    testUnitConstruction<HumanHealer>(humanHealer);
    testCreatureConstruction<HumanHealer>(std::dynamic_pointer_cast<Creature>(humanHealer));
    EXPECT_EQ(humanHealer->getHeal(), HumanHealer::defaultStartHeal);
    EXPECT_EQ(humanHealer->getHealRange(), HumanHealer::defaultStartHealRange);

    std::cout << "HUMAN HEALER CONSTRUCTING TEST PASSED" << std::endl;

    std::shared_ptr<Healer> orcHealer = getUnit<Healer>([this]() {
        return orcFactory->getHealer(defaultXPos, defaultYPos);
    });
    testUnitConstruction<OrcHealer>(orcHealer);
    testCreatureConstruction<OrcHealer>(std::dynamic_pointer_cast<Creature>(orcHealer));
    EXPECT_EQ(orcHealer->getHeal(), OrcHealer::defaultStartHeal);
    EXPECT_EQ(orcHealer->getHealRange(), OrcHealer::defaultStartHealRange);

    std::cout << "ORC HEALER CONSTRUCTING TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, AttackFlagTest) {
    std::shared_ptr<IMap> map = std::make_shared<Map>();
    std::shared_ptr<HumanWarrior> humanWarrior = std::make_shared<HumanWarrior>(map, 0, 0);
    std::shared_ptr<OrcWarrior> orcWarrior = std::make_shared<OrcWarrior>(map, 1, 0);
    EXPECT_EQ(orcWarrior->attack(humanWarrior), SUCCESSFUL_ATTACK);

    orcWarrior = std::make_shared<OrcWarrior>(map, floor(OrcWarrior::defaultStartAttackRange + 2), 0);
    EXPECT_EQ(orcWarrior->attack(humanWarrior), SMALL_RANGE_ATTACK);

    std::shared_ptr<OrcArcher> orcArcher = std::make_shared<OrcArcher>(map,
                                                                       floor(OrcArcher::defaultStartAttackRange / 2), 0);
    EXPECT_EQ(orcArcher->attack(humanWarrior), SUCCESSFUL_ATTACK);

    EXPECT_EQ(orcWarrior->attack(nullptr), BAD_TARGET_ATTACK);

    std::shared_ptr<IMap> otherMap = std::make_shared<Map>();
    std::shared_ptr<HumanWarrior> otherHumanWarrior = std::make_shared<HumanWarrior>(otherMap);

    EXPECT_EQ(orcWarrior->attack(otherHumanWarrior), BAD_TARGET_ATTACK);

    std::cout << "ATTACK FLAG TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, AttackTest) {
    std::shared_ptr<IMap> map = std::make_shared<Map>();
    std::shared_ptr<HumanWarrior> humanWarrior = std::make_shared<HumanWarrior>(map, 0, 0);
    std::shared_ptr<OrcWarrior> orcWarrior = std::make_shared<OrcWarrior>(map,
                                                                          floor(OrcWarrior::defaultStartAttackRange - 1),
                                                                          0);
    orcWarrior->attack(humanWarrior);
    EXPECT_EQ(humanWarrior->getHealth() < HumanWarrior::defaultStartHealth, true);

    humanWarrior = std::make_shared<HumanWarrior>(map, 0, 0, 1);
    orcWarrior->attack(humanWarrior);
    EXPECT_EQ(humanWarrior->getHealth(), 0);

    std::cout << "ATTACK TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, HealFlagTest) {
    std::shared_ptr<IMap> map = std::make_shared<Map>();
    std::shared_ptr<HumanWarrior> humanWarrior = std::make_shared<HumanWarrior>(map, 0, 0,
                                                                                HumanWarrior::defaultStartHealth / 2);
    std::shared_ptr<HumanHealer> humanHealer = std::make_shared<HumanHealer>(map,
                                                                             floor(HumanHealer::defaultStartHealRange - 1),
                                                                             0);
    EXPECT_EQ(humanHealer->heal(humanWarrior), SUCCESSFUL_HEAL);

    humanHealer = std::make_shared<HumanHealer>(map, floor(HumanHealer::defaultStartHealRange + 2), 0);
    EXPECT_EQ(humanHealer->heal(humanWarrior), SMALL_RANGE_HEAL);

    EXPECT_EQ(humanHealer->heal(nullptr), BAD_TARGET_HEAL);

    std::shared_ptr<IMap> otherMap = std::make_shared<Map>();
    std::shared_ptr<HumanWarrior> otherHumanWarrior = std::make_shared<HumanWarrior>(otherMap);

    EXPECT_EQ(humanHealer->heal(otherHumanWarrior), BAD_TARGET_HEAL);

    std::cout << "HEAL FLAG TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, HealTest) {
    std::shared_ptr<IMap> map = std::make_shared<Map>();
    std::shared_ptr<HumanWarrior> humanWarrior = std::make_shared<HumanWarrior>(map, 0, 0,
                                                                                HumanWarrior::defaultStartHealth / 2);
    std::shared_ptr<HumanHealer> humanHealer = std::make_shared<HumanHealer>(map,
                                                                             floor(HumanHealer::defaultStartHealRange - 1),
                                                                             0);
    humanHealer->heal(humanWarrior);
    EXPECT_EQ(humanWarrior->getHealth() > HumanWarrior::defaultStartHealth / 2, true);

    humanWarrior = std::make_shared<HumanWarrior>(map, 0, 0);
    humanHealer->heal(humanWarrior);
    EXPECT_EQ(humanWarrior->getHealth(), HumanWarrior::defaultStartHealth);

    std::cout << "HEAL TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, MoveFlagTest) {
    std::shared_ptr<IMap> map = std::make_shared<Map>();
    std::shared_ptr<HumanWarrior> humanWarrior = std::make_shared<HumanWarrior>(map, 0, 0);
    EXPECT_EQ(humanWarrior->moveTo(humanWarrior->getMoveRange(), 0), SUCCESSFUL_MOVE);
    EXPECT_EQ(humanWarrior->moveBy(-humanWarrior->getMoveRange(), 0), SUCCESSFUL_MOVE);
    EXPECT_EQ(humanWarrior->moveTo(humanWarrior->getMoveRange() + 10, 0), SMALL_RANGE_MOVE);
    EXPECT_EQ(humanWarrior->moveBy(-humanWarrior->getMoveRange() - 10, 0), SMALL_RANGE_MOVE);

    std::shared_ptr<IMap> map1 = std::make_shared<Map>();
    std::shared_ptr<HumanWarrior> humanWarrior1 = std::make_shared<HumanWarrior>(map1, 0, 0);
    humanWarrior1->putOnMap();
    std::shared_ptr<HumanWarrior> humanWarrior2 = std::make_shared<HumanWarrior>(map1, 0, 1);
    humanWarrior2->putOnMap();
    EXPECT_EQ(humanWarrior1->moveTo(0, 1), ENGAGED_MOVE);
    EXPECT_EQ(humanWarrior1->moveBy(0, 1), ENGAGED_MOVE);

    std::cout << "MOVE FLAG TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, MoveTest) {
    std::shared_ptr<IMap> map = std::make_shared<Map>();
    std::shared_ptr<HumanWarrior> humanWarrior = std::make_shared<HumanWarrior>(map, 0, 0);

    humanWarrior->moveTo(humanWarrior->getMoveRange(), 0);
    EXPECT_EQ(humanWarrior->getPosition().first, humanWarrior->getMoveRange());
    EXPECT_EQ(humanWarrior->getPosition().second, 0);

    humanWarrior->moveBy(-humanWarrior->getMoveRange(), 0);
    EXPECT_EQ(humanWarrior->getPosition().first, 0);
    EXPECT_EQ(humanWarrior->getPosition().second, 0);

    humanWarrior->moveTo(humanWarrior->getMoveRange() + 10, 0);
    EXPECT_EQ(humanWarrior->getPosition().first, 0);
    EXPECT_EQ(humanWarrior->getPosition().second, 0);

    humanWarrior->moveBy(-humanWarrior->getMoveRange() - 10, 0);
    EXPECT_EQ(humanWarrior->getPosition().first, 0);
    EXPECT_EQ(humanWarrior->getPosition().second, 0);

    std::cout << "MOVE TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, WorkerBuilding) {
    std::shared_ptr<Worker> humanWorker = getUnit<Worker>([this]() {
        return humanFactory->getWorker(defaultXPos, defaultYPos);
    });

    std::shared_ptr<Building> building = humanWorker->buildTownHall();
    EXPECT_EQ(building->getId(), HumanTownHall::id);

    building = humanWorker->buildTownHall(humanWorker->getMoveRange() + HumanTownHall::xSize + 10, defaultYPos);
    EXPECT_EQ(building, nullptr);

    building = humanWorker->buildBarracks();
    EXPECT_EQ(building->getId(), HumanBarracks::id);

    building = humanWorker->buildBarracks(humanWorker->getMoveRange() + HumanTownHall::xSize + 10, defaultYPos);
    EXPECT_EQ(building, nullptr);


    std::shared_ptr<Worker> orcWorker = getUnit<Worker>([this]() {
        return orcFactory->getWorker(defaultXPos, defaultYPos);
    });

    building = orcWorker->buildTownHall();
    EXPECT_EQ(building->getId(), OrcTownHall::id);

    building = orcWorker->buildTownHall(orcWorker->getMoveRange() + OrcTownHall::xSize + 10, defaultYPos);
    EXPECT_EQ(building, nullptr);

    building = orcWorker->buildBarracks();
    EXPECT_EQ(building->getId(), OrcBarracks::id);

    building = orcWorker->buildBarracks(orcWorker->getMoveRange() + OrcTownHall::xSize + 10, defaultYPos);
    EXPECT_EQ(building, nullptr);

    std::cout << "WORKER BUILDING TEST PASSED" << std::endl;
}

TEST_F(UnitsTest, BuildingProduction) {
    std::shared_ptr<TownHall> townHall = getUnit<TownHall>([this]() {
        return humanFactory->getTownHall(defaultXPos, defaultYPos);
    });
    std::shared_ptr<Unit> creature = townHall->createWorker();
    EXPECT_EQ(creature->getId(), HumanWorker::id);

    townHall = getUnit<TownHall>([this]() {
        return orcFactory->getTownHall(defaultXPos, defaultYPos);
    });
    creature = townHall->createWorker();
    EXPECT_EQ(creature->getId(), OrcWorker::id);

    std::shared_ptr<Barracks> barracks = getUnit<Barracks>([this]() {
        return humanFactory->getBarracks(defaultXPos, defaultYPos);
    });
    creature = barracks->createWarrior();
    EXPECT_EQ(creature->getId(), HumanWarrior::id);

    creature = barracks->createArcher();
    EXPECT_EQ(creature->getId(), HumanArcher::id);

    creature = barracks->createHealer();
    EXPECT_EQ(creature->getId(), HumanHealer::id);

    barracks = getUnit<Barracks>([this]() {
        return orcFactory->getBarracks(defaultXPos, defaultYPos);
    });
    creature = barracks->createWarrior();
    EXPECT_EQ(creature->getId(), OrcWarrior::id);

    creature = barracks->createArcher();
    EXPECT_EQ(creature->getId(), OrcArcher::id);

    creature = barracks->createHealer();
    EXPECT_EQ(creature->getId(), OrcHealer::id);

    std::cout << "BUILDING PRODUCTION TEST PASSED" << std::endl;
}


#endif /* UnitsTest_hpp */
