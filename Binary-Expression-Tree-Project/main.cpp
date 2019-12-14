#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "binaryExpressionTree.h"


using namespace std;

int main() 
{
  ifstream inFile;
  inFile.open("RpnData.txt");
  string postExpression;
  binaryExpressionTree binaryExpression;
  getline(inFile,postExpression);
  while(!inFile.eof())
  {
    binaryExpression.buildExpressionTree(postExpression);

    cout << "Expression result of " << postExpression << " is " << binaryExpression.evaluateExpressionTree() << endl;
    binaryExpression.destroyTree();
    getline(inFile,postExpression);
  }
  inFile.close();


  return 0;
}