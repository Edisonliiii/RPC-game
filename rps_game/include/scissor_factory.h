#ifndef SCISSOR_FACTORY_H_
#define SCISSOR_FACTORY_H_

#include "scissor.h"
#include "rpc_factory.h"

// build scissor and return unique pointer
class ScissorFactory : public RpcFactory
{
public:
  std::unique_ptr<Rpc> make() const override
  {
    return std::make_unique<Scissor>();
  }
  ~ScissorFactory(){}
}

#endif // SCISSOR_FACTORY_H_