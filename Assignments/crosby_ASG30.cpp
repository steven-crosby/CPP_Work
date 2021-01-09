/*************************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Brother Foushee, CS124
*    
* Author:
*    Steven Crosby
*    
* Summary: 
*    Prompt the user for 10 grades, calculate the average, and print the
*    results to the screen.
*
*    Estimated:  2 hrs   
*    Actual:     1 hrs
*
* Please describe briefly what was the most difficult part:
*
*************************************************************************/
#include <iostream>
using namespace std;

void getGrades(short grades[], short numGrades);
float averageGrades(short grades[]);

/*************************************************************************
 * PROMPT USER FOR FILE CONTAINING GRADES AND CALCULATE THE AVERAGE
 *************************************************************************/
int main()
{
   short grades[10]; // grades array

   getGrades(grades, 10);

   cout << "Average Grade: " << averageGrades(grades) << "%\n";

   return 0;
}

/*************************************************************************
 * PROMPT USER FOR TEN GRADES THEN UPDATE ARRAY
 *************************************************************************/
void getGrades(short grades[], short numGrades)
{
   for (short iGrades = 0; iGrades < numGrades; iGrades++)
   {
      // prompt user for grades
      cout << "Grade " << iGrades + 1 << ": ";
      cin >> grades[iGrades]; // update grades array
   }

   return;
}

/*************************************************************************
 * FIND AVERAGE OF THE GRADES
 *************************************************************************/
float averageGrades(short grades[])
{
   short sum = 0;       // sum of grades
   short iGrades = 0;   // iterator (number of grades)

   for (iGrades; iGrades < 10; iGrades++)
   {
      sum += grades[iGrades];
   }

   float average = ((float)sum / iGrades); // average of grades array

   return average;
}