#include <gtest/gtest.h>
#include "../inc/Player.hpp"

struct PlayerTest : public ::testing::Test{};

TEST_F(PlayerTest, loadCorrectData){
    Player p;
    EXPECT_EQ(p.loadData("Edek:5/|5/|5/|5/|5/|5/|5/|5/|X|5/||5X"), true);
}

TEST_F(PlayerTest, loadWrongData){
    Player p;
    EXPECT_EQ(p.loadData("Edek:5/|5X|5/|5/|5/|5/|5/|5/|X|5/||5X"), false);
}

/* need help with this:
TEST_F(PlayerTest, loadCorrectDataCheckName){
    Player p;
    EXPECT_EQ(p.loadData("Edek:5/|5/|5/|5/|5/|5/|5/|5/|X|5/||5X"), p.getName() == "Edek");
}
*/