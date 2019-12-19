// tests.cpp
#include "sequencer.h"
#include <gtest/gtest.h>

int called = 0;
void cb()
{
    called++;
}

TEST(sequencer, doesntCallNoteOn)
{
    called = 0;
    Sequencer s(4, &cb);
    s.tick();
    ASSERT_EQ(0, called);
}

TEST(sequencer, callsNoteOnForEnabledSteps)
{
    called = 0;
    Sequencer s(4, &cb);
    s.setStep(1, true);
    s.tick();
    ASSERT_EQ(0, called);
    s.tick();
    ASSERT_EQ(1, called);
    s.tick();
    ASSERT_EQ(1, called);
}

TEST(sequencer, wrapsAround)
{
    called = 0;
    Sequencer s(4, &cb);
    s.setStep(0, true);
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
TEST(sequencer, wrapsAroundAfterSteps)
{
    called = 0;
    Sequencer s(2, &cb);
    s.setStep(0, true);
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

TEST(sequencer, setAndGetStep)
{
    Sequencer s(2, &cb);
    s.setStep(0, true);
    ASSERT_TRUE(s.getStep(0));
    s.setStep(0, false);
    ASSERT_FALSE(s.getStep(0));
}

TEST(sequencer, getCurrentStep)
{
    Sequencer s(2, &cb);
    s.tick();
    ASSERT_EQ(0, s.getCurrentStep());
    s.tick();
    ASSERT_EQ(1, s.getCurrentStep());
    s.tick();
    ASSERT_EQ(0, s.getCurrentStep());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
