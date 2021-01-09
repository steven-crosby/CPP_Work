/***********************************************************************
* Program:
*   Project 03, Monthly Budget
*   Brother Foushee, CS124
* Author:
*   Steven Crosby
* Summary: 
*   Write a program that prompts the user for his or her income, taxes,
*   expenses, etc. and display the results on the screen in a table.
*
*   Estimated:  2.0 hrs   
*   Actual:     5.0 hrs
*
* Please describe briefly what was the most difficult part:
*
*   The instructions within the book were very very limited
*   Figuring out the proper order and developing the functions
*   was the most difficult.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Main function will gather user input 
 * and print out a monthly budget
 ***********************************************************************/

// Prototypes 
double getIncome();
double getBudgetLiving();
double getActualLiving();
double getActualTax();
double getActualTithing();
double getActualOther();
void displayBudget(double income, double budLiving, double actLiving,
      double budTax, double actTax, double budTithing, double actTithing,
      double budOther, double actOther, double budTotal, double actTotal);
/**********************************************************************
* MONTHLY BUDGET
* Prompt the user for input and display the input back in a table.
***********************************************************************/
int main()
{
// Display Greeting and Instructions
   cout << "This program keeps track of your monthly budget\n"
      << "Please enter the following:\n";

// Income variable 
   double income = getIncome();

// Budget Variables
   double budLiving = getBudgetLiving();
   double budTax = 0;
   double budTithing = (float)(income * 0.1);
   double budOther = (float)(income - budTax - 
      budTithing - budLiving);
   double budTotal = 0;

// Actual Variables
   double actLiving = getActualLiving();
   double actTax = getActualTax();
   double actTithing = getActualTithing();
   double actOther = getActualOther();
   double actTotal = (float)(income - actLiving - 
      actTax - actTithing - actOther);
   
   displayBudget(income,budLiving, actLiving,
      budTax, actTax, budTithing, actTithing,
      budOther, actOther, budTotal, actTotal);

   return 0;
}

// Income Function
double getIncome()
{
   double income;

// Ask for monthly income
   cout << "\tYour monthly income: ";

// Apply input to income variable
   cin >> income;
   
   return income;
}

// Budget Living Function
double getBudgetLiving()
{
   double budLiving;

// Ask for budgeted living expenses
   cout << "\tYour budgeted living expenses: ";

// Apply input to budgetLiving variable
   cin >> budLiving;

   return budLiving;
}

// Actual Living Expenses Function
double getActualLiving()
{
   double actLiving;

// Ask for actual living expenses
   cout << "\tYour actual living expenses: ";

// Apply inout to actualLiving variable
   cin >> actLiving;

   return actLiving;
}

// Actual Tax Function
double getActualTax()
{
   double actTaxes;

// Ask for actual taxes
   cout << "\tYour actual taxes withheld: ";

// Apply input to actualTaxes variable
   cin >> actTaxes;

   return actTaxes;
}

// Actual Tithing Function
double getActualTithing()
{
   double actTithing;

// Ask for actual tithing
   cout << "\tYour actual tithe offerings: ";

// Apply input to actualTithing variable
   cin >> actTithing;

   return actTithing;
}

// Actual Other Expenses Function
double getActualOther()
{
   double actOther;

// Ask for actual other expenses
   cout << "\tYour actual other expenses: ";

// Apply input to actualOther variable
   cin >> actOther;

   return actOther;
}

// Display results as table
void displayBudget(double income,
      double budLiving, double actLiving,
      double budTax, double actTax,
      double budTithing, double actTithing,
      double budOther, double actOther,
      double budTotal, double actTotal)
{
// Configure output for budget data
   cout.setf(ios::fixed); 
   cout.setf(ios::showpoint);
   cout.precision(2);

// Table skeleton
   cout << "\nThe following is a report on your monthly expenses\n"
      << "\tItem                  Budget          Actual\n"
      << "\t=============== =============== ===============\n";

// User-defined entries (next five "cout" commands)
   cout << "\tIncome"
      << setw(11) << "$"
      << setw(11) << income
      << setw(5) << "$"
      << setw(11) << income << endl;
   cout << "\tTaxes"
      << setw(12) << "$"
      << setw(11) << budTax
      << setw(5) << "$"
      << setw(11) << actTax << endl;
   cout << "\tTithing"
      << setw(10) << "$"
      << setw(11) << budTithing
      << setw(5) << "$"
      << setw(11) << actTithing << endl;
   cout << "\tLiving"
      << setw(11) << "$"
      << setw(11) << budLiving
      << setw(5) << "$"
      << setw(11) << actLiving << endl;
   cout << "\tOther"
      << setw(12) << "$"
      << setw(11) << budOther
      << setw(5) << "$"
      << setw(11) << actOther << endl;

// Separator
   cout << "\t=============== =============== ===============\n";

// End calculations
   cout << "\tDifference"
      << setw(7) << "$"
      << setw(11) << budTotal
      << setw(5) << "$"
      << setw(11) << actTotal << endl;
}