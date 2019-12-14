#include <string>
#include <iostream>
#include "addressType.h"

using namespace std;

void addressType::setAddress(string address)
{
  dAddress = address;
}

void addressType::setCity(string city)
{
  dCity = city;
}

void addressType::setState(string state)
{
  if(state.length() > 2)
    dState = "XX";
  else
    dState = state;
}

void addressType::setZipcode(int zipcode)
{
  if(zipcode >= 11111 && zipcode <= 99999)
    dZipcode = zipcode;
  else
    dZipcode = 10000;
}

string addressType::getAddress() const
{
  return dAddress;
}

string addressType::getCity() const
{
  return dCity;
}

string addressType::getState() const
{
  return dState;
}

int addressType::getZipcode() const
{
  return dZipcode;
}

void addressType::print()
{
  cout << dAddress << endl;
  cout << dCity << ", " << dState << " " << dZipcode << endl;
}

addressType::addressType(string address, string city, string state, int zipcode)
{
 setAddress(address);
 setCity(city);
 setState(state);
 setZipcode(zipcode);
}

addressType::~addressType()
{
}