#include <iostream>

using namespace std;

void reverse(int[], int, int);

int main() {
  int low, high;

  int intArray[] = {1,2,3,4,5,6,7,8,9,10};

  int *pArray = new int[10];
  


  int len = sizeof(intArray)/sizeof(intArray[0]);

  for (int i = 0; i < len; i++)//initializing dynamic array
    pArray[i] = intArray[i];


  cout << "The lowest index is 0" << endl; 
  cout << "The highest index is " << len-1 << endl;

    cout << "Enter a low index: ";
    cin >> low; 
    cout << "Enter a high index: ";
    cin >> high;
    cout << endl;
    while(low >= high)// if low index is higher than high index, go back and enter them again.
    {
      cout << "low index must be smaller than high index\n\n";
      cout << "low index: ";
      cin >> low;
      cout << "high index: ";
      cin >> high;
    }

  cout << "Array before switching: ";    
  for (int i = 0; i < len; i++)
  {
    cout << pArray[i] << " ";
  }
  cout << endl;

  reverse(pArray, low, high);

  cout << "Array after switching: ";
  for(int i = 0; i < len; i++)
    cout << pArray[i] << " ";

  delete [] pArray;
  return 0;
}

void reverse(int Array[], int low, int high)
{
  if(low >= high){} // if low and high is equal, stop the function. 

  else// swap the low element and high element.
  {
    int temp = Array[low];
    Array[low] = Array[high];
    Array[high] = temp;
    reverse(Array, low+1, high-1);
  }
}
