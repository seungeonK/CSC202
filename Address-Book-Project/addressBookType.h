#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

#include "extPersonType.h"


class addressBookType
{
  public:
  void addEntry(extPersonType);
  //A function to add an entry into a object
  //Precondition: the length of the list should not be over 500.

  void findPerson(string );
  //A function to find the person based on input
  //Postcondition: print the entry with the lastname input.

  void findBirthdays(int );
  //A function to find the person based on input
  //Postcondition: print the entry with the month input.

  void findRelations(string );
  //A function to find the person based on input
  //Postcondition: print the entry with the relationship input.

  void print();
  //A fuction to print all entries stored in object list.

  void sortEntries();
  //A fuction to sort entries in an alphabetical order.
  

  void initEntries();
  //A fuction to initiate entry.

  void addPerson();
  //A fuction to add a person's entry into the object list.

  private:
  int length = 0;
  int maxLength = 500;
  extPersonType addressList[500];
};

#endif