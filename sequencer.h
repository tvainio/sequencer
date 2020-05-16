// SEQUENCER.h
#ifndef SEQUENCER_H
#define SEQUENCER_H

#define MAX_STEPS 16

typedef void (*callBack)(void);

class Sequencer
{

private:
  callBack noteOnFunction;
  bool stepState[MAX_STEPS] = {false};
  int currentStep = 0;
  int steps = MAX_STEPS;

public:
  Sequencer(int steps, callBack noteOn);
  void setStep(int step, bool status);
  bool getStep(int step);
  int getCurrentStep();
  inline bool *get() { return stepState; };
  inline bool getCurrentStepState() { return this->getStep(this->getCurrentStep()); }

  void tick();
};

#endif
