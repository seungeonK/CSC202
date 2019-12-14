#include <iostream>
#include <string>
#include <fstream>

#include "addressBookType.h"

using namespace std;

void addressBookType::addEntry(extPersonType& objectPerson)
{
  this->insert(objectPerson);
  //end
}

void addressBookType::findPerson(std::string last)
{
  nodeType<extPersonType> *current;
  current = this->first;
  std::cout << "----------list----------\n";
  while(current != nullptr)
  {
    if(current->info.getLastName() == last)
    {
      current->info.print();
      cout << '\n';
      current = current->link;
    }
    else
      current = current->link;
  }
}

void addressBookType::findBirthdays(int month)
{
  std::cout << "----------list----------\n";
  nodeType<extPersonType> *current;
  current = this->first;
  while(current != nullptr)
  {
    if(current->info.getBirthMonth() == month)
    {
      current->info.print();
      cout << '\n';
      current = current->link;
    }
    else
    {
      current = current->link;
    }
  }
}

void addressBookType::findRelations(std::string relationship)
{
  std::cout << "----------list----------\n";
  nodeType<extPersonType> *current;
  current = this->first;
  while(current != nullptr)
  {
    if(current->info.getRelationship() == relationship)
    {
      current->info.print();
      cout << '\n';
      current = current->link;
    }
    else
    {
      current = current->link;
    }
  }
}

void addressBookType::print()
{
  std::cout << "----------list----------\n";
  nodeType<extPersonType> *current;
  current = this->first;
  while(current != nullptr)
  {
    current->info.print();
    cout << '\n';
    current = current->link;
  }
}


void addressBookType::initEntries()
{
  ifstream inFile;
  char discard;
  inFile.open("AddressBookData.txt");
  std::string first, last, address, city, state, phoneNumber, relationship;
  int month, day, year, zipcode;
  inFile >> first;
  while(!inFile.eof())
  {
    inFile >> last >> month >> day >> year;
    inFile.get(discard);
    std::getline(inFile, address);
    std::getline(inFile, city);
    inFile >> state >> zipcode >> phoneNumber >> relationship;
    extPersonType aPerson(first, last, month, day, year, address, city, state, zipcode, phoneNumber, relationship);
    addEntry(aPerson);
    inFile >> first;
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

void addressBookType::removeEntry(const string last)
{
  extPersonType deleteMe(" ", last);
  deleteNode(deleteMe);
  cout << "-----Removed-----" << endl;
  cout << '\n';
}

void addressBookType::save()
{
  ofstream outFile;
  outFile.open("AddressBookData.txt");
  nodeType<extPersonType> *current;
  current = this->first;
   while(current != nullptr)
    {
      outFile << current->info.getFirstName() << " " << current->info.getLastName() << endl;
      outFile << current->info.getBirthMonth() << " " << current->info.getBirthDate() << " " << current->info.getBirthYear() << endl;
      outFile << current->info.getStreet() << endl;
      outFile << current->info.getCity() << endl;
      outFile << current->info.getState() << endl;
      outFile << current->info.getZipcode() << endl;
      outFile << current->info.getPhoneNumber() << endl;
      outFile << current->info.getRelationship() << endl;
      current = current->link;
    }

  outFile.close();

}
