#include "computer.h"

Computer::~Computer()
{
  this->_computer_choice = nullptr;
  delete this->_strategy;
  this->_strategy = nullptr;
}

void Computer::PickChoice(char const* choice)
{
  choice = ConfigStrategy();
  this->_computer_choice = nullptr;
  this->_computer_choice = this->_choice_maker.make_choice(choice);
}

char const* Computer::GetChoice()
{
  return this->_computer_choice->ShowShot();
}

char const* Computer::ConfigStrategy(char const* strategy_choice)
{
  // first reserve incoming history
  if (strategy_choice == nullptr)
  {
    this->_strategy = new StrategyPureRandom();
  }
  else if (strcmp(strategy_choice, "Y"))
  {
    this->_strategy = new StrategyHighestWinRate();
  }
  return this->_strategy->ComplyStrategy(_self_history);
}

// r-0, p-1, s-2
void Computer::GetGameInformation(int result, int c_bet, int h_bet)
{
  ++this->_self_history[c_bet][result];
}