/*************************************************************************
* Program:
*    Assignment 35, Advanced Conditionals
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Your assignment is to write two functions, computeLetterGrade() and 
*    computeGradeSign(), and a single driver program to test them.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
*************************************************************************/


#include <iostream>
using namespace std;


/*************************************************************************
 * Gets the grade from user and sets to int
*************************************************************************/
int getNumGrade()
{
   int numGrade = 0;
   cout << "Enter number grade: ";
   cin >> numGrade;
   return numGrade;
}

/*************************************************************************
 * Computes letter grade
*************************************************************************/
void computeLetterGrade(int numGrade, char &gradeLetter)
{
   switch (numGrade / 10)
   {
      case 10:
      case 9:
         gradeLetter = 'A';
         break;
      case 8:
         gradeLetter = 'B';
         break;
      case 7:
         gradeLetter = 'C';
         break;
      case 6:
         gradeLetter = 'D';
         break;
      default:
         gradeLetter = 'F';
   }
}

/*************************************************************************
 * Computes whether (-) or (+) is applied to letter grade
*************************************************************************/
void computeGradeSign(int numGrade, char &gradeSign)
{
   if (numGrade == 100)
   {
      return;
   }
   if (numGrade <= 60 || numGrade >= 97)
      return;
   int  calcGrade = numGrade % 10;

   switch (calcGrade)
   {
      case 0:
      case 1:
      case 2:
         gradeSign = '-';
         break;
      default:
         break;
      case 7:
      case 8:
      case 9:
         gradeSign = '+';
         break;
   }
}

/*************************************************************************
 * Calls gradeLetter and gradeSign and displays output
*************************************************************************/
int main()
{
   char gradeLetter;
   char gradeSign = '0';
   int numGrade = getNumGrade();
   computeLetterGrade(numGrade, gradeLetter);
   computeGradeSign(numGrade, gradeSign);
   cout << numGrade << "% is " << gradeLetter;
   if (gradeSign == '0')
   {
      cout  << endl;
      return 0;
   }
   cout << gradeSign << endl;
   return 0;
}