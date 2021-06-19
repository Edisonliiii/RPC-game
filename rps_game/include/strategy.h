#ifndef STRATEGY_H_
#define STRATEGY_H_

class Strategy
{
public:
  virtual ~Strategy() {}
  virtual char const* ComplyStrategy() = 0;
};

#endif // STRATEGY_H_