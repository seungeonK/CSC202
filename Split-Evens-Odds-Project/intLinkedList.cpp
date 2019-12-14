#include "intLinkedList.h"
#include <iostream>

void intLinkedList::splitEvensOddsList(intLinkedList &evenItem, intLinkedList &oddItem)
  {
    nodeType<int> *cursor;
    cursor = this->first;
    
    while(cursor != nullptr)
    {
      if (cursor->info % 2 == 0) // even number
      {
        if(evenItem.first == nullptr && evenItem.last == nullptr)// when evenItem is pointing to nothing,
        {
          evenItem.first = cursor;//first and last point to the same first node.
          evenItem.last = cursor;
          cursor = cursor->link;//move cursor to the next node
          evenItem.last->link = nullptr;//the node to which first and last point set to 0.
          evenItem.count++;//increment the count
        }
        else// when evenItem is pointing to the nodes, don't move the first pointer.
        {
          evenItem.last->link = cursor;
          evenItem.last = cursor;
          cursor = cursor->link;
          evenItem.last->link = nullptr;
          evenItem.count++;
        }
      }
      else //odd number
      {
        if (oddItem.first == nullptr && oddItem.last == nullptr)
        {
          oddItem.first = cursor; 
          oddItem.last = cursor;
          cursor = cursor->link;
          oddItem.last->link = nullptr;
          oddItem.count++;
        }
        else
        {
          oddItem.last->link = cursor;
          oddItem.last = cursor;
          cursor = cursor->link;
          oddItem.last->link = nullptr;
          oddItem.count++;
        }
      }
    }

    if(cursor == nullptr)//clean up the orginal 'first' and 'last'. set count as 0. 
    {
      
      this->first = nullptr;
      this->last = nullptr;
      this->count = 0;
    }
  }
