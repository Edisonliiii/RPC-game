#ifndef STRATEGY_PURE_RANDOM_H_
#define STRATEGY_PURE_RANDOM_H_

#include "strategy.h"

class StrategyPureRandom : public Strategy
{
public:
  char const* ComplyStrategy() override;
};

#endif // STRATEGY_PURE_RANDOM_H_