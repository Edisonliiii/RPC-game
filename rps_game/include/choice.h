#ifndef CHOICE_H_
#define CHOICE_H_

#include <map>
#include <memory>
#include <functional>
#include <string>

#include "rpc_options.h"
#include "rock.h"
#include "paper.h"
#include "scissor.h"

class Choice
{
private:
  std::map<std::string, std::function<std::unique_ptr<Rpc>()>> factory;
public:
  Choice()
  {
    factory["Rock"] = []() {
      std::unique_ptr<Rpc> rock = std::make_unique<Rock>();
      return rock;
    };
    factory["Paper"] = []() {
      std::unique_ptr<Rpc> paper = std::make_unique<Paper>();
      return paper;
    };
    factory["Scissor"] = []() {
      std::unique_ptr<Rpc> scissor = std::make_unique<Scissor>();
      return scissor;
    };
  }
  inline std::unique_ptr<Rpc> make_choice(const std::string& name)
  {
    return factory[name]();
  }
};

#endif // CHOICE_H_