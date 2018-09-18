#include <gtest/gtest.h>
#include "../inc/Validator.hpp"

struct ValidatorTest : public ::testing::Test{};

TEST_F(ValidatorTest, finishedFullGame5spare){
    Validator v;
    EXPECT_EQ(v("Edek:5/|5/|5/|5/|5/|5/|5/|5/|X|5/||5X"), true);
}

TEST_F(ValidatorTest, gameInProgressMixed){
    Validator v;
    EXPECT_EQ(v("Name1:X|7/|9-|X|8-|8/|-"), true);
}

TEST_F(ValidatorTest, shortGameInProgressMixed){
    Validator v;
    EXPECT_EQ(v("k:5"), true);
}

TEST_F(ValidatorTest, nonameGameInProgres){
    Validator v;
    EXPECT_EQ(v(":5-|3/|X|X|31|--|X"), true);
}

TEST_F(ValidatorTest, toShortGame){
    Validator v;
    EXPECT_EQ(v(":5"), false);
}

TEST_F(ValidatorTest, finishedGameBadBonusPoints){
    Validator v;
    EXPECT_EQ(v("Player2:X|7/|9-|X|8-|8/|-6|X|X|X||/1"), false);
}

TEST_F(ValidatorTest, finishedGameNoNameSeparator){
    Validator v;
    EXPECT_EQ(v("Player2X|7/|9-|X|8-|8/|-6|X|X|X||X1"), false);
}

TEST_F(ValidatorTest, finishedGameStrikeAndThrowInOneFrame){
    Validator v;
    EXPECT_EQ(v("Player2:X|7/|9-|X1|8-|8/|-6|X|X|X||41"), false);
}

TEST_F(ValidatorTest, finishedGameTwoSparesInOneFrame){
    Validator v;
    EXPECT_EQ(v("Player2:X|7/|9-|X|8-|//|-6|X|X|X||XX"), false);
}

TEST_F(ValidatorTest, finishedGameToMuchBonusMoves){
    Validator v;
    EXPECT_EQ(v("Player2:X|7/|9-|X|8-|X|-6|X|X|X||XX3"), false);
}

TEST_F(ValidatorTest, finishedGameToMuchBonusMoves1){
    Validator v;
    EXPECT_EQ(v("Player2:31|7/|9-|31|8-|X|-6|X|X|X||XX3"), false);
}

TEST_F(ValidatorTest, finishedGameToMuchBonusMoves2){
    Validator v;
    EXPECT_EQ(v("Player2:31|7/|9-|-1|8-|12|-6|5/|5/|5/||32"), false);
}

TEST_F(ValidatorTest, finishedGameReversedSpare){
    Validator v;
    EXPECT_EQ(v("Player2:31|7/|9-|-1|8-|12|-6|/5|5/|5/||3"), false);
}

TEST_F(ValidatorTest, finishedGameBadCharacter){
    Validator v;
    EXPECT_EQ(v("Player2:31|G/|9-|-1|8-|12|-6|35|5/|5/||3"), false);
}

TEST_F(ValidatorTest, finishedGameTwoBonusSeparators){
    Validator v;
    EXPECT_EQ(v("Player2:31|1/|9-|-1|8-|X||-6|35|5/|5/||3"), false);
}

TEST_F(ValidatorTest, finishedGameTooMuchFrames){
    Validator v;
    EXPECT_EQ(v("Player2:31|1/|9-|-1|8-|X|-6|35|5/|X|5/||3X"), false);
}

TEST_F(ValidatorTest, finishedGameLastSeparatorIsNotDual){
    Validator v;
    EXPECT_EQ(v("Player2:31|1/|9-|-1|8-|X|-6|35|5/|X|5/|3X"), false);
}

TEST_F(ValidatorTest, finishedGameOnlyOnePointInFrame){
    Validator v;
    EXPECT_EQ(v("Edek:5/|5/|5/|5/|5/|5/|5/|5/|5|5/||X3"), false);
}

TEST_F(ValidatorTest, finishedGameWierdPlayerName){
    Validator v;
    EXPECT_EQ(v("xxXXxx|<Puppy5l4yer>|xxXXxx:5/|5/|5/|5/|5/|5/|5/|5/|X|5/||5X"), true);
}