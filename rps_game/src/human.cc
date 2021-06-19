#include "human.h"
#include "string.h"

Human::~Human()
{
  this->_human_choice = nullptr;
}

void Human::PickChoice(char const* choice)
{
  this->_human_choice = nullptr;
  
  if (HumanChoiceValidator(choice)) // good input
  {
    this->_human_choice = this->_choice_maker.make_choice(choice);
  }
  else // illigal input
  {
    std::cout << "Bad Input" << std::endl;
    exit(1);
  }
}

char const* Human::GetChoice()
{
  return this->_human_choice->ShowShot();
}

bool Human::HumanChoiceValidator(char const* choice)
{
  if (strcmp(choice, "Rock") && 
      strcmp(choice, "Paper") &&
      strcmp(choice, "Scissor"))
  {
    return false;
  }
  return true;
}