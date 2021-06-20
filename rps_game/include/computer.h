#ifndef RPCGAME_COMPUTER_H_
#define RPCGAME_COMPUTER_H_
// system dependency
#include <vector>
// user-defined dependency
#include "player.h"
#include "choice.h"
#include "strategy_pure_random.h"
#include "strategy_highest_win_rate.h"

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
  // [TODO]: depress int vector to bitwise long vector
  std::vector<std::vector<int>> _self_history = std::vector<std::vector<int>>(3, std::vector<int>(3, 0));
  // [TODO]: easy to extend and get other's history, will do
  
  // Config new game strategy, once the wining rate lower than 50%,
  // it will automatically change the mode
  // There are 2 modes for now: pure_random and highest_win_rate
  // even both are stupid, but the arch is extensible
  // [Parameter]: strategy_choice(char const*): 
  // [Return]: "Rock" / "Paper" / "Scissor"
  char const* ConfigStrategy(char const* strategy_choice = nullptr);
  // Get game informaiton from Game after each round
  // This method will reserve the game history
  // [Parameter]: result(int): result for each round, 0 - human win, 1 - computer win, 2 - draw
  //              c_bet(int) : computer's bet, 0 - Rock, 1 - Paper, 2 - Scissor
  //              h_bet(int) : human's  bet ,  0 - Rock, 1 - Ppaer, 2 - Scissor
  // [Return]: None
  void GetGameInformation(int result=0, int c_bet=0, int h_bet=0) override;
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