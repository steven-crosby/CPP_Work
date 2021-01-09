/*************************************************************************
* Program:
*    Assignment 13, Expressions
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Write a program to convert Fahrenheit to Celsius. This program will 
*    prompt the user for the Fahrenheit number and convert it to Celsius. 
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      Please describe briefly what was the most difficult part.
*************************************************************************/

#include <iostream>
using namespace std;

/*************************************************************************
* main() receives fahrenheit temp from user and then converts to celsius
* using C = 5/9(F-32) formula.
*************************************************************************/
int main()
{
   // Get fahrenheit temp from user
   cout << "Please enter Fahrenheit degrees: ";
   
   int fahrTemp = 0;
   cin >> fahrTemp;

   // Convert from Fahrenheit to Celsius. C = 5 / 9 (F - 32)
   float celsTemp = (double)((5.0 / 9.0) * (fahrTemp - 32));
   
   cout.setf(ios::fixed);
   cout.precision(0);
   
   // write result (temp in Celsius) to screen
   cout << "Celsius: "  << celsTemp << endl;

   return 0;
}

