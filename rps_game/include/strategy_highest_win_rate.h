#ifndef STRATEGY_HIGHEST_WIN_RATE_H_
#define STRATEGY_HIGHEST_WIN_RATE_H_

#include "strategy.h"

class StrategyHighestWinRate : public Strategy
{
public:
  char const* ComplyStrategy(std::vector<std::vector<int>>& history) const override;
};

#endif // STRATEGY_HIGHEST_WIN_RATE_H_