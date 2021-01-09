/****************************************************************************
* Program:
*    Project 04, Monthly Budget
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Write a program that prompts the user for his or her income, taxes,
*    expenses, etc. and display the results on the screen in a table.
*
*    Estimated:  2.0 hrs   
*    Actual:     2.0 hrs
*
* Please describe briefly what was the most difficult part:
*    This was not very difficult at this point in the project.
*    Mostly I just needed to inser the function from the book
*    and properly define it in the program. The biggest challenge now
*    is getting a near perfect score with the styleChecker.
****************************************************************************/

#include <iostream>
#include <iomanip>  // we will use setw() in this example
using namespace std;

// PROTOTPYES
double getIncome();
double getBudgetLiving();
double getActualLiving();
double getActualTax();
double getActualTithing();
double getActualOther();
double computeTax(double income);
void display(double income,
             double budLiving, double actLiving,
             double budTax, double actTax,
             double budTithing, double actTithing,
             double budOther, double actOther,
             double budTotal, double actTotal);

/****************************************************************************
* MONTHLY BUDGET
* Prompt the user for input and display the input back in a table.
****************************************************************************/
int main()
{

   // instructions
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";

   // income
   double income        = getIncome();
   // budgeted
   double budLiving  = getBudgetLiving();
   double budTax     = computeTax(income);
   double budTithing = income * 0.1;
   double budOther   = income - budTax - budTithing - 
                          budLiving;
   double budTotal   = 0;
   // actual
   double actLiving  = getActualLiving();
   double actTax     = getActualTax();
   double actTithing = getActualTithing();
   double actOther   = getActualOther();
   double actTotal   = income - actLiving - actTax -
                          actTithing - actOther;

   display(income,
           budLiving, actLiving,
           budTax, actTax,
           budTithing, actTithing,
           budOther, actOther,
           budTotal, actTotal);

   return 0;

}

/****************************************************************************
* GET INCOME
* Ask for user monthly income and return the value.
****************************************************************************/
double getIncome()
{

   double income;

   // prompt the user for his/her monthly income
   cout << "\tYour monthly income: ";

   // apply input to income
   cin >> income;

   return income;
}

/****************************************************************************
* GET BUDGETED LIVING EXPENSES
* Ask user for their budget living expenses and return the value.
****************************************************************************/
double getBudgetLiving()
{

   double budLiving;

   // prompt for budgeted living expenses
   cout << "\tYour budgeted living expenses: ";

   // apply input to budLiving
   cin >> budLiving;

   return budLiving;
}

/****************************************************************************
* GET ACTUAL LIVING EXPENSES
* Ask user for their acutal living expenses and return the value.
****************************************************************************/
double getActualLiving()
{

   double actLiving;

   // prompt user for actual living expenses
   cout << "\tYour actual living expenses: ";

   // apply input to actLiving
   cin >> actLiving;

   return actLiving;
}

/****************************************************************************
* GET ACTUAL TAXES
* Ask user for actual tax withheld and return the value.
****************************************************************************/
double getActualTax()
{

   double actTaxes;

   // prompt user for actual taxes withheld
   cout << "\tYour actual taxes withheld: ";

   // apply input to actTaxes
   cin >> actTaxes;

   return actTaxes;
}

/****************************************************************************
* GET ACTUAL TITHING
* Ask user for actual tithing paid and return the value.
****************************************************************************/
double getActualTithing()
{

   double actTithing;

   // prompt user for tithing paid
   cout << "\tYour actual tithe offerings: ";

   // apply input to actTithing
   cin >> actTithing;

   return actTithing;
}

/****************************************************************************
* GET ACTUAL OTHER EXPENSES
* Ask user for actual other expenses and return the value.
****************************************************************************/
double getActualOther()
{

   double otherExpenses;

   // prompt user for actual other expenses
   cout << "\tYour actual other expenses: ";

   // apply input to otherExpenses
   cin >> otherExpenses;

   return otherExpenses;
}

/****************************************************************************
 * COMPUTE TAX
 * Convert user's monthly income to annual income. Determine tax liability
 * based on that value and return computeTax value.
 ****************************************************************************/
double computeTax(double income)
{
   // multiply income by 12 for yearly figure
   double yearlyIncome = (income * 12.0);
   double yearlyTax = 0;

   // determine which tax amount to use
   // 10% bracket
   if (yearlyIncome > 0 && yearlyIncome < 15100.0)
   {
      yearlyTax = (yearlyIncome * 0.10);
   }
   // 15% bracket
   else if (yearlyIncome < 61300.0)
   {
      yearlyTax = (1510.0 + ((yearlyIncome - 15100.0) * 0.15));
   }
   // 25% bracket
   else if (yearlyIncome < 123700.0)
   {
      yearlyTax = (8440.0 + ((yearlyIncome - 61300.0) * 0.25));
   }
   // 28% bracket
   else if (yearlyIncome < 188450.0)
   {
      yearlyTax = (24040.0 + ((yearlyIncome - 123700.0) * 0.28));
   }
   // 33% bracket
   else if (yearlyIncome < 336550.0)
   {
      yearlyTax = (42170.0 + ((yearlyIncome - 188450.0) * 0.33));
   }
   // 35% bracket
   else
   {
      yearlyTax = (91043.0 + ((yearlyIncome - 336550.0) * 0.35));
   }

   // divide tax amount by 12 for monthly amount
   double monthlyTax = (yearlyTax / 12.0);

   return monthlyTax;
}

/****************************************************************************
* DISPLAY MONTHLY BUDGET
* Display the results as a table.
****************************************************************************/
void display(double income,
             double budLiving, double actLiving,
             double budTax, double actTax,
             double budTithing, double actTithing,
             double budOther, double actOther,
             double budTotal, double actTotal)
{

   // money display output config
   cout.setf(ios::fixed);     // no scientific notation
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(2);         // two decimals for cents

   // summary, headers, and row separators
   cout << "\nThe following is a report on your monthly expenses\n"
        << "\tItem                  Budget          Actual\n"
        << "\t=============== =============== ===============\n";
   // User input in following cout
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
   // row separator (=)
   cout << "\t=============== =============== ===============\n";
   // End calculations
   cout << "\tDifference"
        << setw(7) << "$"
        << setw(11) << budTotal
        << setw(5) << "$"
        << setw(11) << actTotal << endl;
}