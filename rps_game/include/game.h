#ifndef GAME_H_
#define GAME_H_

#include <vector>

#include "computer.h"
#include "human.h"

class Game
{
private:
  Computer _computer;
  Human _human;

  void Welcome();
  void MakeBet();
  void GameReferee();
public:
  void RunGame();
};

#endif // GAME_H_
