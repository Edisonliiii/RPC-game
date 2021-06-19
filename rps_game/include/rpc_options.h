#ifndef RPC_OPTIONS_H_
#define RPC_OPTIONS_H_

class Rpc
{
public:
  virtual char const* ShowShot() = 0;
  virtual ~Rpc(){}
};

#endif // RPC_OPTIONS_H_