#ifndef RPCGAME_COMPUTER_H_
#define RPCGAME_COMPUTER_H_

#include <vector>

#include "player.h"
#include "choice.h"
#include "strategy_pure_random.h"

// Player Computer with decoupled Strategy changing with history
// It is also an observer of Game.
// Example:
//    Simply include computer.h
class Computer : public Player
{
private:
  // reserve current choice (Rpc: Rock/Paper/Scissor)
  std::unique_ptr<Rpc> _computer_choice;
  // factory obj which will return a new choice and assign to _computer_choice
  Choice _choice_maker;
  // Strategy pointer used to interchange different strategies
  Strategy* _strategy;
  // Record game history
  // [ToDo]: depress int vector to bitwise long vector
  std::vector<pair<int, int>> history;
  
  // Config new game strategy
  // [Return]: "Rock" / "Paper" / "Scissor"
  char const* ConfigStrategy();
public:
  // c'tor
  Computer() : _computer_choice(nullptr), _strategy(nullptr){}
  // d'tor
  // [Delete]: _computer_choice & _strategy
  ~Computer();
  // Choice setter
  // [Parameter]: choice(="Rock"/"Paper"/"Scissor")
  // [Return]: None
  void PickChoice(char const* choice=nullptr) override;
  // Choice Getter
  // [Parameter]: None
  // [Return]: choice string description ("Rock"/"Paper"/"Scissor")
  char const* GetChoice() override;
};
#endif // RPCGAME_COMPUTER_H_