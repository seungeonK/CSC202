#include <iostream>
#include "intLinkedList.h"

using namespace std;

int main() 
{ 
  intLinkedList list;
  intLinkedList evenList;
  intLinkedList oddList;
  
  int input;
  int maxSize = 100;
  int values[maxSize];

  cout << "Enter intergers ending with -999: ";
  cin >> input;
  int cnt = 0;
  values[cnt] = input;

  while(input != -999)
  {
    cin >> input;
    cnt++;
    values[cnt] = input;
  }
  
  for(int i = 0; i < cnt; i++)
    list.insertLast(values[i]);

  
cout << "Original List before spliting: ";
list.print();
cout << "\n\n";

list.splitEvensOddsList(evenList, oddList);


linkedListIterator<int> it;//iterator variable.

cout << "Even List: ";
for(it = evenList.begin(); it != evenList.end(); ++it)
  {
    cout << *it << " ";
  }

 cout << endl;
 cout << endl;

cout << "Odd List: ";

 for(it = oddList.begin(); it != oddList.end(); ++it)
    cout << *it << " ";

cout << "\n\n";

cout << "Original List: ";

 for(it = list.begin(); it != list.end(); ++it)
    cout << *it << " ";



  return 0;
}



