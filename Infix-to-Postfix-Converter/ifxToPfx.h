#include "myStack.h"
#include <string>


class ifxToPfx: public stackType<char>
{
public:
    ifxToPfx(); //constructor.
                //declare and initialize ifx and pfx

    const string getInfix();
    //A fuction to print infix expression

    const void setInfix(ifstream&);
    //A fuction to read infix expression.

    const string getPostfix();
    //A fuction to output post expression.

    void evaluateExpression();
    //A fuction to convert infix expression to postfix expression.

    int precedence(const char&);
    //A fuction to evaluate the precedence of operators.
    //Postcondition: return int value depending on the precedence of operators. returns higher when the precedence is greater.

private:
    string ifx;
    string pfx;
};