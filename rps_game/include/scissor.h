#ifndef SCISSOR_H_
#define SCISSOR_H_

#include "rpc_options.h"

class Scissor : public Rpc
{
public:
  char const* ShowShot() override
  {
    return "Scissor";
  }
  virtual ~Scissor(){}
};

#endif // SCISSOR_H_