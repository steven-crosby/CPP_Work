/*************************************************************************
* Program:
*    Assignment 42, String Class
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Write a function to generate the Dem Bones song. This function takes 
*    an array of strings as input and returns a single string that 
*    constitutes the entire song as output:
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
*************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string generateSong(string list[], int num);

/*************************************************************************
 * MAIN function feeds string list to generateSong function and displays 
 * as a string to the user
*************************************************************************/
int main()
{
   string list[9] =
      {"toe","foot","leg","knee","hip","back","neck","jaw","head" };
   
   // Call generateSong()
   string song = generateSong(list, 9);

   // Display output
   cout << song;
   
   return 0;
}

/*************************************************************************
 * generateSong() function generates a single string that constitutes 
 * the entire song as output
*************************************************************************/
string generateSong(string list[], int num)
{
   string output;
   for (int i = 0; i < 8; i++)
   {
      output += list[i] + " bone connected to the " + list[i + 1] + " bone\n";
   }
   return output;
}