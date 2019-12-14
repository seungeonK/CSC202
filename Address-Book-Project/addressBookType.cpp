#include <iostream>
#include <string>
#include <fstream>
#include "addressBookType.h"


void addressBookType::addEntry(extPersonType objectPerson)
{
  if (length <= maxLength)
  {
    addressList[length] = objectPerson;
    length++;
  }
  sortEntries();
  //end
}

void addressBookType::findPerson(std::string last)
{
  std::cout << "----------list----------\n";
  for(int i = 0; i < length; i++)
  {
    if(addressList[i].getLastName() == last)
    {
      addressList[i].print();
      std::cout << '\n';
    }
  }
}

void addressBookType::findBirthdays(int month)
{
  std::cout << "----------list----------\n";
 for(int i = 0; i < length; i++)
 {
   if(addressList[i].getBirthMonth() == month)
   {
    addressList[i].print();
    std::cout << '\n';
   }
 }
}

void addressBookType::findRelations(std::string relationship)
{
  std::cout << "----------list----------\n";
  for(int i = 0; i < length; i++)
  {
   if(addressList[i].getRelationship() == relationship)
   {
      addressList[i].print();
      std::cout << '\n';
   }
 }
}

void addressBookType::print()
{
  std::cout << "----------list----------\n";
  for(int i = 0; i < length; i++)
  {
    addressList[i].print();
    std::cout << '\n';
  }
}

void addressBookType::sortEntries()
{
  for(int current = 1; current < length; current++)  
  {
    int index = current;
    bool placeFound = false;
    while(index > 0 && !placeFound)
    {
      if (addressList[index].getLastName() < addressList[index - 1].getLastName())// if the value of the key is smaller than the left one, it should switch each other.
      {
        extPersonType temp = addressList[index];//set temp to list[index]
        addressList[index] = addressList[index - 1];//assign larger number to the left index.
        addressList[index-1] = temp;
        index--;
      }
      else // if the two values are sorted orderly, it stops.
        placeFound = true;
    }
  } 
}

void addressBookType::initEntries()
{
  ifstream inFile;
  char discard;
  inFile.open("AddressBookData.txt");
  std::string first, last, address, city, state, phoneNumber, relationship;
  int month, day, year, zipcode;
  while(!inFile.eof())
  {
    inFile >> first >> last >> month >> day >> year;
    inFile.get(discard);
    std::getline(inFile, address);
    std::getline(inFile, city);
    inFile >> state >> zipcode >> phoneNumber >> relationship;
    extPersonType aPerson(first, last, month, day, year, address, city, state, zipcode, phoneNumber, relationship);
    addEntry(aPerson);
  }
  inFile.close();
}

void addressBookType::addPerson()
{
  char discard;
  std::string first, last, address, city, state, phoneNumber, relationship;
  int month, day, year, zipcode;
  std::cout << "Add a person's first name: ";
  std::cin >> first;
  std::cout << "Add a person's last name: "; 
  std::cin >> last;
  std::cout << "Add a person's street address: ";
  std::cin >> discard; // skip the whitespace.
  std::getline(std::cin, address);
  std::cout << "Add a person's city: ";
  std::getline(std::cin, city);
  std::cout << "Add a person's state: ";
  std::cin >> state;
  std::cout << "Add a person's zipcode: ";
  std::cin >> zipcode;
  std::cout << "Add a person's month of birthday: ";
  std::cin >> month;
  std::cout << "Add a person's date of birthday: ";
  std::cin >> day;
  std::cout << "Add a person's year of birthday: ";
  std::cin >> year;
  std::cout << "add a person's phone number(with dash): ";
  std::cin >> phoneNumber;
  std::cout << "What is the relationship with this person?(Friend, Family, Business): ";
  std::cin >> relationship;
  std::cout << "----------Person has been added!----------\n";
  std::cout << '\n';

  extPersonType PersonAdded(first, last, month, day, year, address, city, state, zipcode, phoneNumber, relationship);
  addEntry(PersonAdded);
}
