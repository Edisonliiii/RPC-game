#ifndef RPC_FACTORY_H_
#define RPC_FACTORY_H_

#include <memory>
#include "rpc_options.h"

class RpcFactory
{
public:
  virtual std::unique_ptr<Rpc> make() const = 0;
  virtual ~RpcFactory(){}
};

#endif // RPC_FACTORY_H_