//extPersonType.cpp
#include <string>
#include <iostream>
#include "extPersonType.h"

using namespace std;

void extPersonType::setPhoneNumber(string phoneNumber)
{
  dPhoneNumber = phoneNumber;
}
string extPersonType::getPhoneNumber() const
{
  return dPhoneNumber;
}
void extPersonType::setRelationship(string relationship)
{
  if (relationship != "Family" && relationship != "Friend" && relationship != "Business")
    dRelationship = "None";
  else
    dRelationship = relationship;
  //end
}
string extPersonType::getRelationship() const
{
 return dRelationship;
}

int extPersonType::getBirthMonth() const
{
 return birthday.getMonth();
}

int extPersonType::getBirthDate() const
{
  return birthday.getDay();
}

int extPersonType::getBirthYear() const
{
  return birthday.getYear();
}

string extPersonType::getStreet() const
{
  return (address.getAddress());
}

string extPersonType::getCity() const
{
  return (address.getCity());
}

string extPersonType::getState() const
{
  return address.getState();
}

int extPersonType::getZipcode() const
{
  return (address.getZipcode());
}

void extPersonType::print()
{
  personType::print();
  address.print();
  cout << "Phone Number: " << dPhoneNumber << endl;
  birthday.print();
  cout << endl;
  cout << "relationship: " << dRelationship << endl;
}


extPersonType::extPersonType(string first, string last, int month, int day, int year, string address, string city, string state, int zipcode, string phoneNumber, string relationship)
:personType(first, last), address(address, city, state, zipcode), birthday(month, day, year)//
{
  //validation(a modifier)
  setPhoneNumber(phoneNumber);
  setRelationship(relationship);
}

bool extPersonType::operator==(const extPersonType& right) const
{
  return (this->getLastName() == right.getLastName());
}

bool extPersonType::operator!=(const extPersonType& right) const
{
  return (this->getLastName() != right.getLastName());
}

bool extPersonType::operator>=(const extPersonType& right) const
{
  return (this->getLastName() >= right.getLastName());
}