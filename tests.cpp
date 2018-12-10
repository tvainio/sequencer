// tests.cpp
#include "sequencer.h"
#include <gtest/gtest.h> 

int called = 0;
void cb()
{
    called++;
}

TEST(sequencer, callsNoteOn) {
    Sequencer s(&cb);
    s.tick();
    ASSERT_EQ(1, called);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
