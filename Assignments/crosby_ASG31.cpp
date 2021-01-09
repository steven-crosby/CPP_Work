/*************************************************************************
* Program:
*    Assignment 31, Array Design
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
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
#include <cassert>
using namespace std;

void getGrades(int grades[], int numGrades);
float averageGrades(int grades[]);

/*************************************************************************
 * FIND GRADE AVERAGE
*************************************************************************/
int main()
{
   int grades[10]; 

   getGrades(grades, 10);

   int average = averageGrades(grades);

   // if there are no completed assignments
   if (average == 0)
   {
      cout << "Average Grade: ---%\n";
   } 
   else 
   {
      cout << "Average Grade: " << average << "%\n";
}
return 0;
}

/*************************************************************************
 * GET GRADES
*************************************************************************/
void getGrades(int grades[], int numGrades)
{
   for (int iGrades = 0; iGrades < numGrades; iGrades++)
   {
      cout << "Grade " << iGrades + 1 << ": ";
    
      cin >> grades[iGrades];
   }

   return;
}

/*************************************************************************
 * FIND AVERAGE GRADES
*************************************************************************/
float averageGrades(int grades[])
{
   int sum = 0;            // sum of grades
   int iGrades = 0;        // iterator (number of grades)
   int numIncomplete = 0;  // number of incomplete assignments
   float average = 0;      // average of grades array

   for (iGrades; iGrades < 10; iGrades++)
   {
      if (grades[iGrades] <= 0)
      {
         numIncomplete++;
      } 
      else
      {
         sum += grades[iGrades]; // update the sum of all grades
      }
   }
   if (sum > 0) // calculate average only if sum > 0
   {
      average = ((float)sum / (float)(iGrades - numIncomplete));
   }
   return average;
}