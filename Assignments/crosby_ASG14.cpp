/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother Foushee, CS124
*
* Author:
*    Steven Crosby
*
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  1.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>

/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/

void peterQuestion()
{
   std::cout << "Lord, how oft shall my brother sin against me, and I forgive him?\n";
   std::cout << "Till seven times?\n";
}

void jesusAnswer()
{
   std::cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   std::cout << "times: but, Until " << 7 * 70 << ".\n";
}

int main()
{
   // ask Peter's question
   peterQuestion();

   // the first part of the Lord's response
   jesusAnswer();

   return 0;
}
