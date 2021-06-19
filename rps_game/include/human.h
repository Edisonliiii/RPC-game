#ifndef RPCGAME_HUMAN_H_
#define RPCGAME_HUMAN_H_

#include <iostream>

#include "player.h"
#include "choice.h"

class Human : public Player
{
private:
  std::unique_ptr<Rpc> _human_choice;
  Choice _choice_maker;

  bool HumanChoiceValidator(char const* choice);
public:
  Human() : _human_choice(nullptr) {}
  ~Human();
  void PickChoice(char const* choice) override;
  char const* GetChoice() override;
};

#endif // RPCGAME_HUMAN_H_