// SEQUENCER.h
#ifndef SEQUENCER_H
#define SEQUENCER_H
#include <vector>

typedef void (*callBack)(void);

class Sequencer
{

private:
  callBack noteOnFunction;
  std::vector<bool> stepState;
  int currentStep = 0;
  int steps;

public:
  Sequencer(int steps, callBack noteOn);
  void setStep(int step, bool status);
  bool getStep(int step);
  int getCurrentStep();
  inline bool getCurrentStepState() { return this->getStep(this->getCurrentStep()); }

  void tick();
};

#endif
