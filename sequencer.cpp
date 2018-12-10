#include "sequencer.h"

Sequencer::Sequencer(callBack noteOn)
{
    noteOnFunction = noteOn;
}

void Sequencer::tick()
{
    noteOnFunction();
}
