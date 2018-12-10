// SEQUENCER.h
#ifndef SEQUENCER_H
#define SEQUENCER_H

typedef void (*callBack)(void);

class Sequencer
{

private:
    callBack noteOnFunction;
    
public:
  Sequencer(callBack noteOn);
  void tick();

};

#endif
