#include <string>

#include "game.h"

#define H_WIN 0
#define C_WIN 1
#define DRAW  2

Game::Game()
{
  _computer = new Computer();
  _human = new Human();
  _observers.push_back(_computer);
  _observers.push_back(_human);
}

Game::~Game()
{
  delete _computer;
  _computer = nullptr;
  delete _human;
  _human = nullptr;
}

void Game::Welcome()
{
  std::cout<<"Welcome to the RPS game!"<<std::endl;
}

void Game::MakeBet()
{
  std::cout<<"Please type your bet: ";
  // get user input
  std::string tmp;
  std::getline(std::cin, tmp);
  const char* user_input = new char[10];
  user_input = tmp.data();
  // make bet
  _computer->PickChoice();
  _human->PickChoice(user_input);
}

void Game::GameReferee()
{
  char const* computer_curr_bet = _computer->GetChoice();
  char const* human_curr_bet = _human->GetChoice();
  // transfer string to number
  if (strlen(computer_curr_bet) == 4) _computer_curr_bet = 0;
  else if (strlen(computer_curr_bet) == 5) _computer_curr_bet = 1;
  else if (strlen(computer_curr_bet) == 7) _computer_curr_bet = 2;
  // print result
  std::cout<<"Computer: "<<computer_curr_bet<<std::endl;
  std::cout<<"You: "<<human_curr_bet<<std::endl;
  //std::cout<<strlen(_computer->GetChoice())<<std::endl;
  std::cout << "Here is the result: ";
  if (strlen(computer_curr_bet) == strlen(human_curr_bet))
  {
    std::cout << "Draw!" << std::endl;
    this->_result = DRAW;
  }
  else if (strlen(computer_curr_bet) - strlen(human_curr_bet) == 1 ||
           strlen(computer_curr_bet) - strlen(human_curr_bet) == 2 ||
           strlen(computer_curr_bet) - strlen(human_curr_bet) == -3)
  {
    std::cout << "You Lost!" << std::endl;
    this->_result = C_WIN;
  }
  else
  {
    std::cout << "You Win!" << std::endl;
    this->_result = H_WIN;
  }
  std::cout<<std::endl;
}

void Game::NoticeObservers()
{
  for (int i=0; i<_observers.size(); ++i)
  {
    ((Player*)(_observers[i]))->GetGameInformation(this->_result, this->_computer_curr_bet);
  }
}

void Game::RunGame()
{
  this->Welcome();
  // start game
  while(1)
  {
    std::cout<<"Round: "<<++this->_round<<std::endl;
    this->MakeBet();
    this->GameReferee();
    this->NoticeObservers();
  }
}




