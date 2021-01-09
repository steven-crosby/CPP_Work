/*************************************************************************
* Program:
*    Assignment 26, Files  
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Write a program to read 10 grades from a file and display the 
*    average. This will include the functions getFileName(), 
*    displayAverage() and readFile()
* 
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
*************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/*************************************************************************
 * getFileName() method receives the file name from the user input
*************************************************************************/
void getFileName(char theFileName[])
{
   cout << "Please enter the filename: ";
   cin >> theFileName;
}

/*************************************************************************
 * readFile() method receives the file name from the user input
*************************************************************************/
float readFile(char theFileName[256])
{
   ifstream fin(theFileName);
   if (fin.fail())
   {
      return -1;
   }

   int grades;
   float theAverage = 0;
   int count = 0;
   while (fin >> grades)
   {
      theAverage += grades;
      count++;
   }
   fin.close();

   if (count > 10 || count < 10)
      return -1;


   return theAverage / 10;
}

/*************************************************************************
 * displayAverage() method will display the average score
*************************************************************************/
void display(float theAverage)
{
   cout.setf(ios::fixed);
   cout.precision(0);
   cout <<  "Average Grade: " << theAverage << "%" << endl;
}

/*************************************************************************
 * main() calls getFileName(), readFile(), and displayAverage() and runs 
 * the program
*************************************************************************/
int main()
{
   char theFileName[256];
   getFileName(theFileName);
   float theAverage = readFile(theFileName);
   if (theAverage == -1)
      cout << "Error reading file \"" << theFileName << "\"" << endl;
   else
      display(theAverage);

   return 0;
}