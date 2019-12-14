#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double newtonMethod(double, double, double);

int main()
{
  cout << fixed << setprecision(4); //fix decimal places at 4
  double a, x;
  cout << "Enter a positive integer: ";
  cin >> x;
  a = x;


  double epsilon = 0.0001;

  cout << "The value of 'a' after recursion is " << newtonMethod(x, a , epsilon) << endl;
  cout << "Square root of " << x << " is " << sqrt(x) << endl;
  cout << "The tolerance is less than or equal to " << epsilon << endl;

  return 0;
}

double newtonMethod(double x, double a, double tolerance)
{
  if(abs(a*a-x) <= tolerance)
    return a;
  else
    a = ((a*a + x))/(2*a);
    return newtonMethod(x, a, tolerance);
}