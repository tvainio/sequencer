// SEQUENCER.h
#ifndef SEQUENCER_H
#define SEQUENCER_H

#define STEPS 4

typedef void (*callBack)(void);

class Sequencer
{

private:
  callBack noteOnFunction;
  bool stepState[STEPS] = {false};
  int currentStep = 0;
  
public:
  Sequencer(callBack noteOn);
  void set(int step, bool status);
  void tick();

};

#endif
