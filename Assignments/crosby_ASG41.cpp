/*************************************************************************
* Program:
*    Assignment 41, Allocating Memory
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Write a program to:
*    - Prompt the user for the number of characters in a string.
*    - Allocate a string of sufficient length
*    - Prompt the user for the string using getline().
*    - Display the string back to the user.
*    - Release the memory and check for allocation failures.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
*************************************************************************/
#include <iostream>
using namespace std;

/*************************************************************************
 * Main function calls subroutines
*************************************************************************/
int main()
{
   int numGrades;

   // Prompt user for the number of characters in a string
   cout << "Number of characters: ";
   cin >> numGrades;

   numGrades++;
   char * string = new(nothrow) char[numGrades];
   if (string == NULL)
   {
      cout << "Allocation failure!\n";
      return 0;
   }
   
   // Prompt user for the string using getline()
   cin.ignore();
   cout << "Enter Text: ";
   cin.getline(string, numGrades);
   
   // Display the string back to the user
   cout << "Text: ";
   for (int count = 0; count < numGrades - 1; count++)
   {
      cout << string[count];
   }

   // Delete memory and check for allocation failures
   cout << endl;
   delete [] string;
   string = NULL;
}