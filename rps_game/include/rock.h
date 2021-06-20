#ifndef ROCK_H_
#define ROCK_H_

#include "rpc_options.h"

// Rock
class Rock : public Rpc
{
public:
  char const* ShowShot() override
  {
    return "Rock";
  }
  // d'tor
  virtual ~Rock(){}
};

#endif // ROCK_H_