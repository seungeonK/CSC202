#include <iostream>
#include "tornadoException.h"

int main() 
{
  int input;
  bool set = false;

  do
  {
    try
    {
      std::cout << "How many miles does it have left for tornado to come?: ";

      std::cin >> input;

      if (input <= 0)//if the number is 0 or negative, throw exception with default constructor.
        throw tornadoException();

      else if (input > 0 && input < 50)
      //if the number is less than 50, throw exception of constructor with parameter.
        throw tornadoException(input);

      else if (input >= 50)
      //if the number is large enough, nothing happened.
        std::cout << "Safe\n";
      set = true;
    }

    catch(tornadoException exceptionObj)
    {
      std::cout << "Exception occured\n" << exceptionObj.what() << '\n';
    }
  } 
  while(!set);

  return 0;
}
