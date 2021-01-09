/******************************************************************
* Program:
* Assignment 25, Loop Design
* Brother Foushee, CS124
*
* Author:
* Steven Crosby
*
* Summary: 
* Write a function (displayTable()) to display a calendar on the screen.
* 
*
* Estimated:  0.5 hrs   
* Actual:     0.5 hrs
* Please describe briefly what was the most difficult part
******************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

void displayTable(int numDays, int offset);

/******************************************************************
* MAIN
******************************************************************/
int main()
{
   int numDays;
   int offset;

   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> offset;

   displayTable(numDays, offset);

   return 0;
}
/******************************************************************
* DISPLAY
******************************************************************/
void displayTable(int numDays, int offset)
{
   // max number of days per week (row)
   int fullWeek = offset + 1;
   // calendar header
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;

   // set the first date based on the offset
   for (int i = offset; i >= 0; i--)
   {
      // add 4 spaces for each iteration and if week is not full
      if (fullWeek < 7)
      {
         cout << setw(4) << "  ";
      }
   }
   // reset the week once the max number of days (7) is hit
   if (fullWeek == 7)
   {
      fullWeek = 0;
   }
   // print calendar days
   for (int i = 1; i <= numDays; i++)
   {
      // new row when max number of days is hit and reset the week
      if (fullWeek == 7)
      {
         fullWeek = 0;
         cout << endl;
      }
      cout << setw(4) << i;
      fullWeek++;
   }
   // final line returned to end calendar
   cout << endl;
}