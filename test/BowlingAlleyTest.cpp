#include <gtest/gtest.h>
#include "../inc/BowlingAlley.hpp"

struct BowlingAlleyTest : public ::testing::Test{};

TEST_F(BowlingAlleyTest, assertTrueIsFalse){
    BowlingAlley b;
    EXPECT_EQ(true, false);
}