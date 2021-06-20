#ifndef PAPER_H_
#define PAPER_H_
// user-defined dependency
#include "rpc_options.h"

// paper class
class Paper : public Rpc
{
public:
  // test method
  char const* ShowShot() override
  {
    return "Paper";
  }
  // d'tor
  virtual ~Paper(){}
};

#endif // PAPER_H_