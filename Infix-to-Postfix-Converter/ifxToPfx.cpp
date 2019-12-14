#include "ifxToPfx.h"
#include <string>
#include <fstream>

using namespace std;

ifxToPfx::ifxToPfx()
{
  pfx = "";
  ifx = "";
}

const void ifxToPfx::setInfix(ifstream& inFile)
{
  getline(inFile,ifx,';');
  inFile.get();
}

const string ifxToPfx::getInfix()
{
  return ifx;
}

const string ifxToPfx::getPostfix()
{
  return pfx;
}

void ifxToPfx::evaluateExpression()
{
  pfx = "";
  stackType<char> stack;// create stack
  int len = ifx.length();
  for (int i = 0; i < len; i++)
  {
    if ((ifx[i] >= 'a' && ifx[i] <= 'z') || (ifx[i] >= 'A' && ifx[i] <= 'Z'))//if scanned character is an operand
      pfx += ifx[i];
      
    else if (ifx[i] == '(')//if scanned character is '('
      stack.push(ifx[i]); //push it to stack.

    else if (ifx[i] == ')')
      {
        while(stack.top() != '(')
        {
          char c = stack.top();
          stack.pop();
          pfx += c;//pop and append all of the symbols from the stack until the most recent left parentheses.
        }
        if(stack.top() == '(')
          stack.pop(); //pop discard the left parentheses.
         
      }
      //end if
      
    else if ((ifx[i] == '+') || (ifx[i] == '-') || (ifx[i] == '*') || (ifx[i] == '/'))// if scanned charcter is an operator
    {
      if(stack.isEmptyStack())
        stack.push(ifx[i]);
      else // if there is something already in the stack,
      {
        if(stack.top() == '(')// if the top is (, just push it. no more operators to be moved to pfx.
          stack.push(ifx[i]);
        else// if there is something other than (, priority comparison.
        //end if
        {
          while(!stack.isEmptyStack())
          {
            if(stack.top() == '(')
              break;
            //end if
            char c = stack.top(); 
            if(precedence(ifx[i]) > precedence(c))
            {
              break;
            }
            else //ifx[i] <= c
            {
              stack.pop();
              pfx += c;
            }
            //end if
          }
          stack.push(ifx[i]);
        }
      }
    }
  }

  while(!stack.isEmptyStack())//After processing infx, pop and append the rest of operators left in stack. 
  {
    char c = stack.top();
    pfx += c;
    stack.pop();
  }
}

int ifxToPfx::precedence(const char& opr)
{
  if(opr == '*' || opr == '/')
    return 2;
  else if(opr == '+' || opr == '-')
    return 1;
  else
    return -1;
}
