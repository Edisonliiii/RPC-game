#ifndef PLAYER_H_
#define PLAYER_H_

#include <memory>

// Player interface
// Example:
//    Simply include "player.h" and implement it
class Player
{
public:
  virtual void PickChoice(char const* choice) = 0;
  virtual char const* GetChoice() = 0;
  // no need to implement it if you don't need
  // For computer player, it is necessary to include this
  // For human palyer, there is no need to implement this
  virtual void GetGameInformation(int result=0, int c_bet=0, int h_bet=0) {};
};

#endif // PLAYER_H_