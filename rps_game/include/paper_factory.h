#ifndef PAPER_FACTORY_H_
#define PAPER_FACTORY_H_

#include "paper.h"
#include "rpc_factory.h"

// build paper and return unique pointer
class PaperFactory : public RpcFactory
{
public:
  std::unique_ptr<Rpc> make() const override
  {
    return std::make_unique<Paper>();
  }
  ~PaperFactory(){}
}

#endif // PAPER_FACTORY_H_