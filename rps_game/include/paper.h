#ifndef PAPER_H_
#define PAPER_H_

#include "rpc_options.h"

class Paper : public Rpc
{
public:
  // test method
  char const* ShowShot() override
  {
    return "Paper";
  }
  virtual ~Paper(){}
};

#endif // PAPER_H_