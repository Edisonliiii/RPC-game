#ifndef RPCGAME_COMPUTER_H_
#define RPCGAME_COMPUTER_H_

#include "player.h"
#include "choice.h"
#include "strategy_pure_random.h"

class Computer : public Player
{
private:
  std::unique_ptr<Rpc> _computer_choice; // current choice
  Choice _choice_maker; // factory
  Strategy* _strategy; // strategies

  char const* ConfigStrategy();
public:
  Computer() : _computer_choice(nullptr), _strategy(nullptr){}
  ~Computer();
  void PickChoice(char const* choice=nullptr) override;
  char const* GetChoice() override;
};

#endif // RPCGAME_COMPUTER_H_