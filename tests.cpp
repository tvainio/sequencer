// tests.cpp
#include "sequencer.h"
#include <gtest/gtest.h> 

int called = 0;
void cb()
{
    called++;
}

TEST(sequencer, doesntCallNoteOn) {
    called=0;
    Sequencer s(&cb);
    s.tick();
    ASSERT_EQ(0, called);
}

TEST(sequencer, callsNoteOnForEnabledSteps) {
    called=0;
    Sequencer s(&cb);
    s.set(1, true);
    s.tick();
    ASSERT_EQ(0, called);
    s.tick();
    ASSERT_EQ(1, called);
    s.tick();
    ASSERT_EQ(1, called);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
