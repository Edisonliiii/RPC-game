#include <iostream>

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
  int win_rounds = 0;
  for (int i=0; i<3; ++i)
  {
    for (int j=0; j<3; ++j)
    {
      win_rounds += this->_self_history[i][1];
    }
  }
  // <0.2 || >0.8
  if (win_rounds > ( this->_round / 5 )* 4 || this->_round <= 10)
  {
    //std::cout << "Too easy for the computer!" << std::endl;
    delete this->_strategy;
    this->_strategy = nullptr;
    this->_strategy = new StrategyPureRandom();
  }
  else // [0.2 -- 0.8]
  {
    //std::cout << "Using better strategy!" << std::endl;
    delete this->_strategy;
    this->_strategy = nullptr;
    this->_strategy = new StrategyHighestWinRate();
  }
  return this->_strategy->ComplyStrategy(this->_self_history);
}

// r-0, p-1, s-2
void Computer::GetGameInformation(int result, int c_bet, int h_bet)
{
  ++this->_self_history[c_bet][result];
  ++this->_round;
  int won_rounds = 0;
  int lost_rounds = 0;
  for (int i=0; i<3; ++i)
  {
    for (int j=0; j<3; ++j)
    {
      //std::cout<<this->_self_history[i][j]<<" ";
      if(j==0) won_rounds += this->_self_history[i][j];
      else if(j==1) lost_rounds += this->_self_history[i][j];
    }
  }
  std::cout<<"You Won: "<<won_rounds<<std::endl;
  std::cout<<"You Lost: "<<lost_rounds<<std::endl;
  std::cout<<std::endl;
}