#ifndef TORNADOEXCEPTION_H
#define TORNADOEXCEPTION_H
#include <string>

class tornadoException
{
public:
  tornadoException();

  tornadoException(int);

  std::string what();

private:
  int mile;
  std::string message;
};

#endif