#include <string>

#include "game.h"

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
  _computer.PickChoice();
  _human.PickChoice(user_input);
}

void Game::GameReferee()
{
  char const* computer_curr_bet = _computer.GetChoice();
  char const* human_curr_bet = _human.GetChoice();
  
  // print result
  std::cout<<"Computer: "<<computer_curr_bet<<std::endl;
  std::cout<<"You: "<<human_curr_bet<<std::endl;
  std::cout<<strlen(_computer.GetChoice())<<std::endl;
  std::cout << "Here is the result: ";
  if (strlen(computer_curr_bet) == strlen(human_curr_bet))
  {
    std::cout << "Draw!" << std::endl; 
  }
  else if (strlen(computer_curr_bet) - strlen(human_curr_bet)==1)
  {
    std::cout << "You Lost!" << std::endl;
  }
  else
  {
    std::cout << "You Win!" << std::endl;
  }
}

void Game::RunGame()
{
  this->Welcome();
  int round = 0;
  // start game
  while(1)
  {
    std::cout<<"Round: "<<++round<<std::endl;
    this->MakeBet();
    this->GameReferee();
  }
}




