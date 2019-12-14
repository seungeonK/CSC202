//extPersonType.h
#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H
#include "personType.h"
#include "addressType.h"
#include "dateType.h"

#include <string>

using namespace std;

class extPersonType : public personType
{
public:
  void setPhoneNumber(string);
  //a function to set the phone number
  //Postcondition : phonenumber > dPhoneNumber.
  
  string getPhoneNumber() const;
  //A function to return the phone number from the client.
  //Postcondition: phone number form the client.

  void setRelationship(string);
  //A function to set the relationship.
  //Postcondition : relationship > dRelationship

  string getRelationship() const;
  //A function to return the relationship from the client.
  //Precondition : relationship should be Friend or Family or Business
  //Postcondition : relationship from the client.

  int getBirthMonth() const;
  //A function to return the birthday from the client.
  //Precondition : dateType class
  //Postcondition : birthday from the client.

  void print();

  extPersonType(string first = " ", string last = " ", int month = 1, int day = 1, int year = 1900, string address = " ", string city = " ", string state = "XX", int zipcode = 10000, string phoneNumber = "", string relationship = "None");
  /* Constructor.
  It sets the features of 'PersonType', 'dateType', 'addressType' classes to parameters.
  */

private:
  addressType address;
  dateType birthday;
  string dPhoneNumber;
  string dRelationship;

};
#endif