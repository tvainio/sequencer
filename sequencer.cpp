#include "sequencer.h"

Sequencer::Sequencer(callBack noteOn)
{
    noteOnFunction = noteOn;

}
void Sequencer::set(int step, bool status)
{
    stepState[step] = status;
}

void Sequencer::tick()
{
    if (stepState[currentStep]) {
	noteOnFunction();
    }
    currentStep++;
}
