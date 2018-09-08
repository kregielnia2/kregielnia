#include <gtest/gtest.h>
#include "../inc/Player.hpp"

struct PlayerTest : public ::testing::Test{};

TEST_F(PlayerTest, vagueValidateInputTest){
    Player p;
    EXPECT_EQ(p.validateInput("xoxoxo"), true);
}

TEST_F(PlayerTest, TestName){
//Given: on input for single player 'adam:'
    Player p;
    p.loadData("adam:");
    EXPECT_EQ(p.getName(),"adam");
}
TEST_F(PlayerTest, TestScoreCountOnePoint){
//Given: on input for single player 'adam:1'
    Player p;
    p.loadData("adam:1");
    EXPECT_EQ(p.getPoints(),1);
}
TEST_F(PlayerTest, TestScoreCountOneFrame){
//Given: on input for single player 'adam:1'
    Player p;
    p.loadData("adam:11");
    EXPECT_EQ(p.getPoints(),2);
}
TEST_F(PlayerTest, TestScoreCountTwoFrames){
//Given: on input for single player 'adam:11|11'
    Player p;
    p.loadData("adam:11|11");
    EXPECT_EQ(p.getPoints(),4);
}
TEST_F(PlayerTest, TestScoreCountFrameWithMiss){
//Given: on input for single player 'adam:11|1-'
    Player p;
    p.loadData("adam:11|1-");
    EXPECT_EQ(p.getPoints(),3);
}
TEST_F(PlayerTest, TestScoreCountFrameWithSpare){
//Given: on input for single player 'adam:11|2/'
    Player p;
    p.loadData("adam:11|2/");
    EXPECT_EQ(p.getPoints(),12);
}
TEST_F(PlayerTest, TestScoreCountFrameWithStrike){
//Given: on input for single player 'adam:11|X'
    Player p;
    p.loadData("adam:11|X");
    EXPECT_EQ(p.getPoints(),12);
}
TEST_F(PlayerTest, TestScoreCountOnePinAndPrevFrameStrike){
//Given: on input for single player 'adam:X|1'
    Player p;
    p.loadData("adam:X|1");
    EXPECT_EQ(p.getPoints(),12);
}
TEST_F(PlayerTest, TestScoreCountTwoPinsAndPrevFrameStrike){
//Given: on input for single player 'adam:X|11'
    Player p;
    p.loadData("adam:X|11");
    EXPECT_EQ(p.getPoints(),14);
}
TEST_F(PlayerTest, TestScoreCountOnePinAndPrevFrameSpare){
//Given: on input for single player 'adam:1/|1'
    Player p;
    p.loadData("adam:1/|1");
    EXPECT_EQ(p.getPoints(),12);
}
TEST_F(PlayerTest, TestScoreCountComplicated){
//Given: on input for single player 'adam:3-|X|4/|5'
    Player p;
    p.loadData("adam:3-|X|4/|5");
    EXPECT_EQ(p.getPoints(),43);
}
TEST_F(PlayerTest, TestScoreCountComplicated2){
//Given: on input for single player 'adam:3-|X|4/|5'
    Player p;
    p.loadData("adam:-1|X|11|2/|11");
    EXPECT_EQ(p.getPoints(),28);
}
