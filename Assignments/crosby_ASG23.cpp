/******************************************************************
* Program:
*    Assignment 23, Loop Syntax
*    Brother Foushee, CS124
*
* Author:
*   Steven Crosby
*
* Summary: 
*   Sue wants to make sure that her brother gets a 100% on each
* 
*
*   Estimated:  0.5 hrs   
*   Actual:     0.5 hrs
*      Please describe briefly what was the most difficult part
******************************************************************/

#include <iostream>
using namespace std;

/******************************************************************
* finding the sum of multiples using loop syntax
******************************************************************/
int getMultiple()
{
   cout << "What multiples are we adding? ";
   int number;
   cin >> number;
   return number;
}
int addMultiples(int multiple)
{
   int sum = 0;
   int end = 100;
   for (int count = multiple; count < 100; count += multiple)
   {
      sum += count;
   }
   return sum;
}
void display(int multiple, int sum)
{
   cout << "The sum of multiples of "
      << multiple
      << " less than 100 are: "
      << sum
      << endl;
   return;
}
int main()
{
   int multiple = getMultiple();
   int sum = addMultiples(multiple);
   display(multiple, sum);
   return 0;
}