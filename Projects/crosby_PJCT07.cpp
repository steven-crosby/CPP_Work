/*************************************************************************
* Program:
*    Project 07, Calendar
*    Bro Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Create a calendar for any month of any year from 1753 forward. This 
*    is similar to the cal utility on the Linux system. Prompt the user 
*    for the numeric month and year to be displayed as shown in the 
*    example below. Your calculations to determine the first day of the 
*    month shall start with January 1, 1753 as a Monday. The challenge 
*    here is to take into account leap years.
*
*    Estimated:  4.0 hrs   
*    Actual:     6.0 hrs
*      Please describe briefly what was the most difficult part.
**************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// prototypes
int getMonth();
int getYear();
int computeOffset(int year, int month);
int numDaysInYear(int year);
int numDaysInMonth(int year, int month);
bool isLeapYear(int year);
void displayHeader(int year, int month);
void displayTable(int numDays, int offset);
void display(int year, int month, int offset);

/*************************************************************************
* Display final output
**************************************************************************/
int main()
{
   int month = getMonth(); // prompt for month
   int year = getYear(); // prompt for year
   int offset = computeOffset(year, month); // offset
   display(year, month, offset); // display result
   
   return 0;
}

/*************************************************************************
* Get a user-defined month
**************************************************************************/
int getMonth()
{
   int month;
   
   do
   {
      cout << "Enter a month number: ";
      cin >> month;

      if (month < 1 || month > 12)
      { 
         cout << "Month must be between 1 and 12.\n"; 
         // error message for invalid input 
      }
   }

   while (month < 1 || month > 12);

   return month;
}

/*************************************************************************
* Get a user-defined year
**************************************************************************/
int getYear()
{
   int year;
   
   do // prompt for year
   {
      cout << "Enter year: ";
      cin >> year;

      if (year < 1753)
      {
         cout << "Year must be 1753 or later.\n";
         // error message for invalid input 
      }
   }

   // continue prompting until proper input received 
   while (year < 1753);

   return year;
}

/*************************************************************************
* Establish offset
**************************************************************************/
int computeOffset(int year, int month)
{
   int totalNumDays = 0;

   for (int i = year - 1; i > 1752; i--)
   {
      totalNumDays += numDaysInYear(i);
   }

   for (int j = month - 1; j > 0; j--)
   {
      totalNumDays += numDaysInMonth((year), j);
   }

   int offset = totalNumDays % 7;

   return offset;
}

/*************************************************************************
* Number of days in year
**************************************************************************/
int numDaysInYear(int year)
{
   bool leapYear = isLeapYear(year);

   int daysInYear = 365;

   if (leapYear)
   {
      daysInYear = 366;
   }

   return daysInYear;
}

/*************************************************************************
* Number of days in month
**************************************************************************/
int numDaysInMonth(int year, int month)
{
   bool leapYear = isLeapYear(year);
   
   int daysInMonth = 0;

   if (month == 4 || month == 6 || month == 9 || month == 11)
   {
      daysInMonth = 30;
   }
   else if (month == 2)
   {
      if (leapYear)
      {
         daysInMonth = 29;
      }
      else
      {
         daysInMonth = 28;
      }
   }
   else
   {
      daysInMonth = 31;
   }

   return daysInMonth;
}

/*************************************************************************
* Determine if leap year
**************************************************************************/
bool isLeapYear(int year)
{
   if (year % 100 == 0 && year % 400 != 0)
   {
      return false;
   }
   else if (year % 4 == 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/*************************************************************************
* Display calendar header
**************************************************************************/
void displayHeader(int year, int month)
{
   cout << endl;

   if (month == 1)
   {
      cout << "January, ";
   }
   else if (month == 2)
   {
      cout << "February, ";
   }
   else if (month == 3)
   {
      cout << "March, ";
   }
   else if (month == 4)
   {
      cout << "April, ";
   }
   else if (month == 5)
   {
      cout << "May, ";
   }
   else if (month == 6)
   {
      cout << "June, ";
   }
   else if (month == 7)
   {
      cout << "July, ";
   }
   else if (month == 8)
   {
      cout << "August, ";
   }
   else if (month == 9)
   {
      cout << "September, ";
   }
   else if (month == 10)
   {
      cout << "October, ";
   }
   else if (month == 11)
   {
      cout << "November, ";
   }
   else
   {
      cout << "December, ";
   }

   cout << year
        << endl;

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n"; // cal header

   return;
}

/*************************************************************************
* Display calendar grid
**************************************************************************/
void displayTable(int numDays, int offset)
{
   int fullWeek = offset + 1; // num days per week

   for (int i = offset; i >= 0; i--) // set first date based on offset
   {

      if (fullWeek < 7) // insert 4 days if necessary
      {
         cout << setw(4) << "  ";
      }

   }

   if (fullWeek == 7) // reset week reached when max num days hit
   {
      fullWeek = 0;
   }

   for (int i = 1; i <= numDays; i++) // display calendar days
   {

      if (fullWeek == 7)
      {
         cout << endl;
         fullWeek = 0;
      }

      cout << setw(4) << i;

      fullWeek++; //increment week
   }

   cout << endl;

}

/*************************************************************************
* Call the header and body for the calendar
**************************************************************************/
void display(int year, int month, int offset)
{
   int numDays = numDaysInMonth(year, month);

   displayHeader(year, month); // display header
   displayTable(numDays, offset); // display table

   return;
}