#ifndef ADRESSTYPE_H_INCLUDED
#define ADRESSTYPE_H_INCLUDED
#include <string>

using namespace std;

class addressType
{
  public:
    void setAddress(string address);
    //A function to set the address.
    //Postcondition: dAddress = address
    
    void setCity(string city);
    //A fuction to set the city.
    //Postcondition: dCity = city;
    
    void setState(string state);
    //A function to set the state.
    //Postcondition: dState = state;

    void setZipcode(int zipcode);
    //A function to set the zipcode.
    //Postcondition: dZipcode = zipcode;

    string getAddress() const;
    //A function that has a return value of address.
    //Postcondition : address from the client.

    string getCity() const;
    //A fuction that has a return value of city.
    //Postcondition : city from the client.
    
    string getState() const;
    //A fuction that has a return value of state.
    //Postcondition : state from the client.

    int getZipcode() const;
    //A fuction that has a return value of zipcode.
    //Postcondition: zipcode from the client.

    void print();
    //A fuction to print the member variables.(address, city, state, zipcode in order.)

    addressType(string address = " ", string city = " ", string state = "XX", int zipcode = 10000);
    //A construnctor with parameters to set the address
    //member variables dAddress, dCity, dState, dZipcode are set here.
    /*Postcondition : dAddress = address
    dCity = city
    dState = state
    dZipcode = zipcode*/
    //if they are not specified, the default values are initialized to the object.

    ~addressType();
    //A destructor to empty the memory allocation.
    
  private:
    string dAddress;
    string dCity;
    string dState;
    int dZipcode;
};
    



#endif // ADRESSTYPE_H_INCLUDED
