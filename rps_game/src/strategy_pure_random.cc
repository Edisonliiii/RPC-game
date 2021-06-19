#include <stdlib.h>
#include <time.h> 

#include "strategy_pure_random.h"

const char* options[3] = {"Rock", "Paper", "Scissor"};

char const* StrategyPureRandom::ComplyStrategy()
{
  srand(time(nullptr));
  int rand_index = 0 + ( rand() % ( 2 - 0 + 1 ));
  return options[rand_index];
}