#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <cctype>
#include "binaryExpressionTree.h"

using namespace std;

void binaryExpressionTree::buildExpressionTree(string pExpression)
{
  stack<nodeType<string>*> nodeStack;

  char *expression = new char [pExpression.length()+1];
  //create a dynamic array.
  strcpy(expression, pExpression.c_str());
  char *token;
  token = strtok(expression, " ");
  do
  {
    //cout << token << endl;
    if(isdigit(token[0]))//if the token is a number.
    {
      nodeType<string> *newNode;
      newNode = new nodeType<string>;//create a new node
      string number = token;
      newNode->info = number;
      nodeStack.push(newNode);
    }
    else if(token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')//if the token is an operator./
    {
      nodeType<string> *newNode;
      newNode = new nodeType<string>;
      newNode->info = token[0];//store the operator into the info field
      //cout << newNode->info << endl;
      if(!nodeStack.empty())
      {
        newNode->rLink = nodeStack.top();//store the reference by 'top()' in the 'rlink' field of the new node.
        nodeStack.pop();
        if(!nodeStack.empty())//if stack is not empty
        {
          newNode->lLink = nodeStack.top();
          nodeStack.pop();
          nodeStack.push(newNode);
        }
        else
          cout << "Error: The stack is empty" << endl;
        //end
      }
      else 
        cout << "Error: The stack is empty" << endl;
      //end
    }
    else
      cout << "Error: unsupported token" << endl;
    //end
  }
  while((token = strtok(NULL, " ")) != NULL);// get the next token until the end
  
  if (!nodeStack.empty())
  {
   // cout << "before popping root" << endl;
    root = nodeStack.top();
    nodeStack.pop();
    //cout << "after popping root" << endl;
    if(!nodeStack.empty())
      root = NULL;
  }
}

double
binaryExpressionTree::evaluateExpressionTree()
{
  return evaluateExpressionTree(root);
}

bool binaryExpressionTree::search(const string& searchItem) const
{
 return true;
}

void binaryExpressionTree::insert(const string& insertItem)
{


}

void binaryExpressionTree::deleteNode(const string& deleteItem)
{

}

double binaryExpressionTree::evaluateExpressionTree(nodeType<string> *p)
{
  if(p->rLink == NULL && p->lLink == NULL)//if leaf node.
  {
    double number = stod(p->info);
    //return the info field of the node
    return number;
  }
  else if(p->info == "+" || p->info == "-" || p->info == "*" || p->info == "/")
  {
    string opr = p->info;
    double leftOpr = evaluateExpressionTree(p->lLink);
    double rightOpr = evaluateExpressionTree(p->rLink);
    if(opr == "+")
      return leftOpr + rightOpr;
    else if(opr == "-")
      return leftOpr - rightOpr;
    else if(opr == "*")
      return leftOpr * rightOpr;
    else if(opr == "/")
      return leftOpr / rightOpr;
  }
  //if the tree has more than one node and the root contains the operator,
  //evaluate the left subtree(recursive)
  //evaluate the right subtree(recursive)
  //apply the operator to the result
  return 0;
}