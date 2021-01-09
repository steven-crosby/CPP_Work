/*************************************************************************
* Program:
*    Assignment 34, Pointers
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Modify countLetters() so that it walks through the string using 
*    pointers instead of array indexes. The output should be exactly 
*    the same as with Assignment 3.2.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
*************************************************************************/

#include <iostream>
using namespace std;

/*************************************************************************
 * This program counts the number of a given letter in a string
*************************************************************************/
void countLetters()
{
   char check;
   char string[256];
   cout << "Enter a letter: ";
   cin >> check;
   int count = 0;
   cout << "Enter text: ";
   cin.ignore();
   cin.getline(string, 256);
   
   for ( char *pString = string; *pString; pString++)
   {
      if ( check == *pString)
         count++;
   }
   cout << "Number of '" << check <<  "'s: " << count << endl;
}

/*************************************************************************
 * main calls function countLetters.
*************************************************************************/
int main()
{
   countLetters();
}
