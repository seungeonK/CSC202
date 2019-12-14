#include <iostream>
#include <fstream>
#include <string>
#include "addressBookType.h"


int main()
{
  int const quit = 6;
  std::string lastName, relationship;
  int birthMonth;
  addressBookType addressEntry;
  addressEntry.initEntries();
  int choice;
  do{
    std::cout << "1) Add a new person into address book.\n";
    std::cout << "2) Find the person/people based on their last names.\n";
    std::cout << "3) Find the person/people based on their birhtdays.\n";
    std::cout << "4) Find the person/peopl based on their relationship.\n";
    std::cout << "5) Print the lists of entries.\n";
    std::cout << "6) Quit and Shut down.\n";
    std::cout << "What would you like to do? Enter a number please: ";
    std::cin >> choice;
    std::cout << endl;
    switch(choice){
      case 1:
        addressEntry.addPerson();
        break;
      case 2:
        std::cout << "Enter last name please: ";
        std::cin >> lastName;
        addressEntry.findPerson(lastName);
        std::cout << endl;
        break;
      case 3:
        std::cout << "Enter month of birthday please: ";
        std::cin >> birthMonth;
        addressEntry.findBirthdays(birthMonth);
        std::cout << endl;
        break;
      case 4:
        std::cout << "Enter the relationship with you please: ";
        std::cin >> relationship;
        addressEntry.findRelations(relationship);
        std::cout << endl;
        break;
      case 5:
        addressEntry.print();
        std::cout << endl;
        break;
      case 6:
        cout << "Thank you\n";
        std::cout << endl;
        break;
      default:
        std::cout << "Invalid choice. Please enter a correct choice.\n";
        std::cout << '\n';   
    }
  }
  while(choice != quit);
  return 0;
}

