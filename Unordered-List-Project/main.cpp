#include <iostream>
#include "unorderedArrayListType.h"

using namespace std;

int main() 
{
  int values[] = {1,2,2,3,4};

  unorderedArrayListType testArray;

  int len = sizeof(values)/sizeof(values[0]);

  for(int i = 0; i < len-1; i++)//
    testArray.insertAt(i,values[i]);

  cout << "array: ";
  for(int i = 0; i < len; i++)
    cout << values[i] << " ";
  cout << "\n\n";

  cout << "duplicate all except for the last element" << endl;
  testArray.print();
  cout << '\n';

  cout << "After deleting all 2s" << endl;
  testArray.removeAll(2);
  testArray.print();
  cout << '\n';

  cout << "After deleting all 5s, which is not in the list" << endl;
  testArray.removeAll(5);
  testArray.print();
  cout << '\n';

  cout << "After insert the last element in the array" << endl;
  testArray.insertEnd(values[len-1]);
  testArray.print();
  cout << '\n';

  cout << "After retriving the value stored at the index of 1" << endl;
  cout << "The value: " << testArray.retrieveAt(1) << endl;
  cout << '\n';
  
  cout << "After retriving the value stored at the index of 100: " << endl;
  cout << '\n';
  cout << testArray.retrieveAt(100) << endl;
  
 return 0; 
}