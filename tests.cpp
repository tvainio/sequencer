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
    Sequencer s(4, &cb);
    s.tick();
    ASSERT_EQ(0, called);
}

TEST(sequencer, callsNoteOnForEnabledSteps) {
    called=0;
    Sequencer s(4, &cb);
    s.set(1, true);
    s.tick();
    ASSERT_EQ(0, called);
    s.tick();
    ASSERT_EQ(1, called);
    s.tick();
    ASSERT_EQ(1, called);
}

TEST(sequencer, wrapsAround) {
    called=0;
    Sequencer s(4, &cb);
    s.set(0, true);
    s.tick();
    ASSERT_EQ(1, called);
    s.tick();
    ASSERT_EQ(1, called);
    s.tick();
    ASSERT_EQ(1, called);
    s.tick();
    ASSERT_EQ(1, called);
    s.tick();
    ASSERT_EQ(2, called);

}
TEST(sequencer, wrapsAroundAfterSteps) {
    called=0;
    Sequencer s(2, &cb);
    s.set(0, true);
    s.tick();
    ASSERT_EQ(1, called);
    s.tick();
    ASSERT_EQ(1, called);
    s.tick();
    ASSERT_EQ(2, called);
    s.tick();
    ASSERT_EQ(2, called);
    s.tick();
    ASSERT_EQ(3, called);

}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
