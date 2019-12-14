//Implementation file date

#include <iostream>
#include "dateType.h"

using namespace std;

void dateType::setDate(int month, int day, int year)
{
  if(!validate(month, day, year))
  {
    dMonth = 1;
    dDay = 1;
    dYear = 1900;
  }
  //end
}

int dateType::getDay() const
{
    return dDay;
}

int dateType::getMonth() const
{
    return dMonth;
}

int dateType::getYear() const
{
    return dYear;
}

void dateType::print() const
{
    cout << dMonth << "-" << dDay << "-" << dYear;
}

bool dateType::isLeapYear(int year) const
{
  if (year % 400 == 0 && year % 100 == 0 && year % 4 == 0)
    return true;
  else if (year % 100 == 0 && year % 4 == 0)
    return false;
  else if (year % 4 == 0)
    return true;
  else
    return false;
  //end
}

bool dateType::validate(int month, int day, int year)
{
  if (year >= 1900)
  {
    dYear = year;
  
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
      dMonth = month;
      if (day > 0 && day < 32)
      {
        dDay = day;
        return true;
      }
      //end
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
      dMonth = month;
      if (day > 0 && day < 31)
      {
        dDay = day;
        return true;
      }
      //end
    }
    else if (month == 2)
    {
      dMonth = month;
      if(isLeapYear(year) == true)
      {
        if (day > 0 && day <= 29)
        {
          dDay = day;
          return true;
        }
        //end
      }
      else if(!isLeapYear(year))//if not leap year
      {
        if (day > 0 && day <= 28)
        {
          dDay = day;
          return true;
        }
        //endl
      }
    }
  }
  return false;
//end
}

//Constructor with parameters
dateType::dateType(int month, int day, int year)
{
  setDate(month, day, year);
}

