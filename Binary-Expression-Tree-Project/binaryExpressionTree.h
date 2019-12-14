#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <string>
#include "binaryTree.h" 

class binaryExpressionTree : public binaryTreeType<string>
{
public:
  void buildExpressionTree(string);

  double evaluateExpressionTree();

  bool search(const string&) const;

  void insert(const string&);

  void deleteNode(const string&);

private:
  
  double evaluateExpressionTree(nodeType<string>* );

};
#endif