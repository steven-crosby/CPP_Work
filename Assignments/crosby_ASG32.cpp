/*************************************************************************
* Program:
*    Assignment 32, Strings
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Assignment is to write the function countLetters() then a driver 
*    program to test it. Determine the number of given letters are in a 
*    given text string.
*
*    Estimated:  2 hrs   
*    Actual:     1 hrs
*
* Please describe briefly what was the most difficult part:
*************************************************************************/
#include <iostream>
#include <cassert>
using namespace std;

int countLetters(const char letter, const char text[]);

/*
* MAIN FUNCTION 
* Determine the number of given letters are in a 
* given text string.
*/
int main()
{
   char text[256];
   char letter;

   cout << "Enter a letter: ";
   cin >> letter;

   cin.ignore();

   cout << "Enter text: ";
   cin.getline(text, 256);

   int numLetters = countLetters(letter, text);

   cout << "Number of '" << letter << "'s: " << numLetters << endl;

   return 0;
}
/*
* COUNT LETTERS
* Determine the number of occurances of a given letter in a given text
* string.
*/
int countLetters(const char letter, const char text[])
{
   int numLetters = 0;

   for (int i = 0; text[i]; i++)
   {
      if (letter == text[i])
      {
         numLetters++;
      }
   }

   return numLetters;
}
