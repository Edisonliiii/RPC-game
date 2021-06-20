#ifndef ROCK_FACTORY_H_
#define ROCK_FACTORY_H_

#include "rock.h"
#include "rpc_factory.h"

// build rock and return unique pointer
class RockFactory : public RpcFactory
{
public:
  std::unique_ptr<Rpc> make() const override
  {
    return std::make_unique<Rock>();
  }
  ~RockFactory(){}
}

#endif // ROCK_FACTORY_H_