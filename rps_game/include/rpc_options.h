#ifndef RPC_OPTIONS_H_
#define RPC_OPTIONS_H_

// Abstraction interfacefor rock paper and scissor
// Simply inherit it and extend your own bet
class Rpc
{
public:
  virtual char const* ShowShot() = 0;
  virtual ~Rpc(){}
};

#endif // RPC_OPTIONS_H_