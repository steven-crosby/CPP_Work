/***********************************************************************
* Program:
*    Project 02, Monthly Budget
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  1.5 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Main function will gather user input 
 * and print out a monthly budget
 ***********************************************************************/
int main()
{
   cout << "This program keeps track of your monthly budget\n";

     // Monthly income declaration
   double income;

     // Budgeted Expenses, and Actual Expenses
   double budgetExpenses;
   double actualExpenses;

     // Taxes, tithings, and other expenses
   double taxes;
   double tithing;
   double other;

     // Prompts and inputs
   cout << "Please enter the following:\n";
   cout << "\tYour monthly income: ";
   cin >> income;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetExpenses;
   cout << "\tYour actual living expenses: ";
   cin >> actualExpenses;
   cout << "\tYour actual taxes withheld: ";
   cin >> taxes;
   cout << "\tYour actual tithe offerings: ";
   cin >> tithing;
   cout << "\tYour actual other expenses: ";
   cin >> other;
   cout << "\n";

     // Display Report
   cout << "The following is a report on your monthly expenses\n";

     // Column headers
   cout << "\tItem"
      << setw(24)
      << "Budget"
      << setw(17)
      << "Actual\n";

     // Dividers
   cout << "\t=============== =============== ==============="
      << "\n";

     // Configure the output
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

     // Rows and items
   cout << "\tIncome"
      << "          $"
      << setw(11)
      << income
      << "    $"
      << setw(11)
      << income
      << "\n";

   cout << "\tTaxes"
      << "           $"
      << setw(11)
      << 0.00
      << "    $"
      << setw(11)
      << taxes
      << "\n";

   cout << "\tTithing"
      << "         $"
      << setw(11)
      << 0.00
      << "    $"
      << setw(11)
      << tithing
      << "\n";

   cout << "\tLiving"
      << "          $"
      << setw(11)
      << budgetExpenses
      << "    $"
      << setw(11)
      << actualExpenses
      << "\n";
      
   cout << "\tOther"
      << "           $"
      << setw(11)
      << 0.00
      << "    $"
      << setw(11)
      << other << "\n";

     // Display dividers
   cout << "\t=============== =============== ===============\n";

     // Display last row of items and money
   cout << "\tDifference"
      << "      $"
      << setw(11)
      << 0.00 << "    $"
      << setw(11)
      << 0.00
      << "\n";

   return 0;
}