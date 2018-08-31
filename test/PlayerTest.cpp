#include <gtest/gtest.h>
#include "../inc/Player.hpp"

struct PlayerTest : public ::testing::Test{};

TEST_F(PlayerTest, vagueValidateInputTest){
    Player p;
    EXPECT_EQ(p.validateInput("xoxoxo"), true);
}