#ifndef H_intLinkedList
#define H_intLinkedList

#include "unorderedLinkedList.h"

class intLinkedList : public unorderedLinkedList<int>
{
public:
  void splitEvensOddsList(intLinkedList &evenItem, intLinkedList &oddItem);
};
#endif