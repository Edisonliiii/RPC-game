#include "computer.h"

Computer::~Computer()
{
  this->_computer_choice = nullptr;
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

char const* Computer::ConfigStrategy()
{
  this->_strategy = new StrategyPureRandom();
  return this->_strategy->ComplyStrategy();
}