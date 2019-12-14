#include <iostream>
#include <string>

using namespace std;


bool isPal(string&, int, int);

int main() {
  while(true)
  {
    string word;
    cout << "Enter a word to check if it is panlindrome: ";
    cin >> word;
    
    if(isPal(word, 0, word.length()-1))
      cout << "This word is a panlindrome.\n\n";
    else
    {
      cout << "This word is NOT a panlindrome.\n";
      cout << "Exited\n\n";
      break;
    }
  }
}


bool isPal(string& checkWord, int start, int end) // madam
{

  if (start == end)
    return true;
  else if(checkWord[start] != checkWord[end])
    return false;
  else // 
    return isPal(checkWord, start+1, end-1); 

  //it first checks if the first index and end index are equal.
  //if the two characters are not same, return false.
  //if they are, call itself with first++ location and end-- location.
  //it does over and over until it checks the first and last indices are same.

}