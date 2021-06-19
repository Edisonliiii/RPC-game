#ifndef PLAYER_H_
#define PLAYER_H_

#include <memory>

class Player
{
public:
  virtual void PickChoice(char const* choice) = 0;
  virtual char const* GetChoice() = 0;
};

#endif // PLAYER_H_