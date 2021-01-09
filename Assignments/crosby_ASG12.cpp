/*************************************************************************
* Program:
*    Assignment 12, Input and Variables
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Write a program that prompts the user for his or her income and 
*    displays the result on the screen
*
*    Estimated:  1.5 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
*************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/*************************************************************************
 * Main function will gather user income and display input
*************************************************************************/
int main()
{
   double income; // use "double" to account for decimals
   
   // prompt the user for his income
   cout << "\t"
      << "Your monthly income: ";
   cin >> income;
   
   // configure the output to display money for monthly income
   cout.setf(ios::fixed);  
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   // display the results 
   cout << "Your income is: $"
      << setw(9) // right aligned to 9 spaces from the dollar sign.
      << income
      << "\n";
   
   return 0;
}