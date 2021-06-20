#ifndef GAME_H_
#define GAME_H_

#include <vector>

#include "computer.h"
#include "human.h"

// Game
// Example:
//    Only public interface, normall use only need one Game to start
class Game
{
private:
  // players: computer & human user
  // ready to extend the #users
  Computer* _computer;
  Human* _human;
  
  // round counting
  int _round;
  // 0 - human win; 1 - computer win; 2 - draw
  int _result;
  // computer's bet in this round
  int _computer_curr_bet;
  // human's bet in this round
  int _human_curr_bet;
  
  // Observers
  // - Computer users should be granted rights on retrieving game info
  // and change the strategy according to the winning rate
  // - Human users should not be granted right on retrieving game info
  std::vector<Player*> _observers;

  // [ Game flow conrol unit ]
  // welcome page
  void Welcome();
  // make bet
  void MakeBet();
  // win or lose
  void GameReferee();
  // Notice every single observers, computer only for now
  void NoticeObservers();
public:
  // c'tor
  Game();
  // d'tor
  ~Game();
  // init the game
  // This method is the only public interface should be called
  void RunGame();
};

#endif // GAME_H_
