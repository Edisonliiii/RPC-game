#ifndef RPCGAME_HUMAN_H_
#define RPCGAME_HUMAN_H_
// system dependency
#include <iostream>
// user-defined dependency
#include "player.h"
#include "choice.h"

// Player Human with decoupled Strategy changing with history
// It is also an observer of Game.
// Example:
//    Simply include computer.h
class Human : public Player
{
private:
  std::unique_ptr<Rpc> _human_choice;
  Choice _choice_maker;
  // check the legit of input
  // [Parameter]: choice(char const*): user input
  // [Return]: true - legal input; false - illegal input
  //           if it is not legal, program will exit
  bool HumanChoiceValidator(char const* choice);
public:
  // c'tor
  Human() : _human_choice(nullptr) {}
  // d'tor
  ~Human();
  // Choice setter
  // [Parameter]: choice(="Rock"/"Paper"/"Scissor") determined by input
  // [Return]: None
  void PickChoice(char const* choice) override;
  // Choice Getter
  // [Parameter]: None
  // [Return]: choice string description ("Rock"/"Paper"/"Scissor")
  char const* GetChoice() override;
  // take the place, no implementation at all.
  void GetGameInformation(int result=0, int c_bet=0, int h_bet=0) override {}
};

#endif // RPCGAME_HUMAN_H_