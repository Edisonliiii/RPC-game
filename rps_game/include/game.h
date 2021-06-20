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
  
  // round counting
  int _round;
  // 0: human win; 1: computer win; 2: draw
  int _result;
  int _computer_curr_bet;
  int _human_curr_bet;
  // observers
  std::vector<Player*> _observers;

  void Welcome();
  void MakeBet();
  void GameReferee();
  // notice every single observers, computer & human for now
  void NoticeObservers();
public:
  Game();
  ~Game();
  void RunGame();
};

#endif // GAME_H_
