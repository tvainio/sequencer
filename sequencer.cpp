#include "sequencer.h"

Sequencer::Sequencer(int steps, callBack noteOn)
{
    this->steps = steps;
    this->noteOnFunction = noteOn;

}
void Sequencer::set(int step, bool status)
{
    this->stepState[step] = status;
}

void Sequencer::tick()
{
    if (stepState[currentStep]) {
	noteOnFunction();
    }
    currentStep++;
    currentStep %= steps;
}
