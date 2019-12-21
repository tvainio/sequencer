#include "sequencer.h"

Sequencer::Sequencer(int steps, callBack noteOn) : stepState(steps, false),
                                                   steps(steps),
                                                   currentStep(steps - 1),
                                                   noteOnFunction(noteOn)
{
}

void Sequencer::setStep(int step, bool status)
{
    this->stepState[step] = status;
}

bool Sequencer::getStep(int step)
{
    return this->stepState[step];
}

int Sequencer::getCurrentStep()
{
    return this->currentStep;
}

void Sequencer::tick()
{
    currentStep++;
    currentStep %= steps;
    if (stepState[currentStep])
    {
        noteOnFunction();
    }
}
