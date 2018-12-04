// tests.cpp
#include "sequencer.h"
#include <gtest/gtest.h> 

TEST(dummyTest, whatever) {
    Sequencer s;
    ASSERT_EQ(1, s.getSum(0,1));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
