#include <iostream>
#include <fstream>
#include "ifxToPfx.h"

using namespace std;

int main() {
ifstream inFile;
  inFile.open("infixData.txt");
  ifxToPfx expression;
  while(!inFile.eof())
  {
  expression.setInfix(inFile);
  cout << "Infix: " << expression.getInfix() << endl;
  expression.evaluateExpression();
  cout << "Postfix: " << expression.getPostfix() << "\n\n";
  }

  
  return 0;
}