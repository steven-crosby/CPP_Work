/*************************************************************************
* Program:
*    Assignment 33, Pointers
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Write a program to ask two people for their account balance. Then, 
*    based on who has the most money, all subsequent purchases will be 
*    charged to his or her account.
*
*    Estimated:  2 hrs   
*    Actual:     1 hrs
*
* Please describe briefly what was the most difficult part:
*************************************************************************/

#include <iostream>
using namespace std;

int main()
{
   double balanceSam;
   double balanceSue;
   double dinner;
   double movie;
   double iceCream;

   double * pAccountBalance;

   cout << "What is Sam's balance? ";
   cin >> balanceSam;
   cout << "What is Sue's balance? ";
   cin >> balanceSue;
   cout << "Cost of the date:\n";
   cout << "\tDinner:    ";
   cin >> dinner;
   cout << "\tMovie:     ";
   cin >> movie;
   cout << "\tIce cream: ";
   cin >> iceCream;

   if (balanceSam > balanceSue)
   {
      pAccountBalance = &balanceSam;
   }
   else
   {
      pAccountBalance = &balanceSue;
   }

   * pAccountBalance -= (dinner + movie + iceCream);

   cout << "Sam's balance: $" << balanceSam << endl;
   cout << "Sue's balance: $" << balanceSue << endl;
}