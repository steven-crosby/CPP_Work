/*************************************************************************
* Program:
*    Assignment 43, Command Line
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Write a program to convert feet to meters
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
*************************************************************************/
#include <cstdlib>
#include <iostream>
using namespace std;

/*************************************************************************
 * Main method scans the command line and calls subroutines
*************************************************************************/
int main(int convert, char ** value)
{
   char meters[] = "0.3048";  // meters per foot
   cout.setf(ios::fixed);     // no scientific notation
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(1);         // two decimals for cents

   // Command line loop
   for (int i = 1; i < convert; i++)
   {
      cout << atof(value[i]) 
           << " feet is "
           << atof(meters) * atof(value[i])
           << " meters\n";
   }

   return 0;
}