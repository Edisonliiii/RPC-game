#ifndef STRATEGY_H_
#define STRATEGY_H_

#include <optional>
#include <vector>
class Strategy
{
public:
  virtual ~Strategy() {}
  virtual char const* ComplyStrategy(std::vector<std::vector<int>>& history) const = 0;
};

#endif // STRATEGY_H_