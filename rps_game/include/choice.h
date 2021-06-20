#ifndef CHOICE_H_
#define CHOICE_H_
// system dependency
#include <map>
#include <memory>
#include <functional>
#include <string>
// user-defined dependency
#include "rpc_options.h"
#include "rock.h"
#include "paper.h"
#include "scissor.h"

// This is the factory hub
// It will produce any materials needed
class Choice
{
private:
  // always-ready factory for best performance
  std::map<std::string, std::function<std::unique_ptr<Rpc>()>> factory;
public:
  // c'tor
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
  // public interface, will be called to get corresponding material
  // [Parameter]: name(const string): "Rock" / "Paper" / "Scissor"
  // [Return]: real object
  inline std::unique_ptr<Rpc> make_choice(const std::string& name)
  {
    return factory[name]();
  }
};

#endif // CHOICE_H_