#include <iostream>
#include <sstream>
#include "tornadoException.h"

tornadoException::tornadoException()
{
  message = "Tornado: Take cover immediately!\n";
}

tornadoException::tornadoException(int m)
{
  mile = m;
  std::stringstream ss;//create stringstream variable.

  ss << "Tornado " << mile << " miles away; and approaching!\n";//load the output into stringstream buffer

  message = ss.str(); //covert the characters into string.
}

std::string tornadoException::what()
{
  return message;
}