#ifndef GAME_H_
#define GAME_H_

#include <vector>

#include "computer.h"
#include "human.h"

// acting like an obsrevee
class Game
{
private:
  Computer* _computer;
  Human* _human;
  
  // observers
  std::vector<Player*> _observers;

  void Welcome();
  void MakeBet();
  void GameReferee();

  void NoticeObservers();
public:
  Game();
  ~Game();
  void RunGame();
};

#endif // GAME_H_
