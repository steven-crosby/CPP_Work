/*************************************************************************
* Program:
*    Project 09, MadLib
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    The second part of the Mad Lib project: read the Mad Lib from a 
*    file and prompt the user.
*
*    Estimated:  3.0 hrs   
*    Actual:     3.0 hrs
*      Please describe briefly what was the most difficult part.
*************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/*************************************************************************
* Prototypes
*************************************************************************/
void getFile(char fileName[]);
void readFile(char fileName[], char word[][32]);
void askQuestions(char word[], int pNull);
void displayStory(char word[][32], int pNull);

/*************************************************************************
* Function gets the file name from user input
*************************************************************************/
void getFile(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
}

/*************************************************************************
* readFile() reads the file that has been retrieved, then calls
* askQuestions() to get user input
*************************************************************************/
void readFile(char fileName[], char word[][32])
{
   ifstream fin;
   fin.open(fileName);

   if (fin.fail())
      cout << "Error reading file: " << fileName;
   
   int size = 0;
   
   while (fin >> word[size])
   {
      size++;
   }

   int pNull = 0;

   for (int i = 0; i < size; i++)
   {
      int pNull = 0;
      
      if (word[i][pNull] == ':')
      {
         askQuestions(word[i], pNull);
      }
      fin.close();
   }
}

/*************************************************************************
* askQuestions() requests user input for Madlib text content
*************************************************************************/
void askQuestions(char word[], int pNull)
{
   if (isalpha(word[1]))
   {
      cout << "\t" << (char)toupper(word[1]);  
      for (int i = 2; word[i]; i++)
      {
         if (word[i] == '_')
            cout << " ";
         else cout << (char)tolower(word[i]);
      }
      cout << ": ";
      
      if (pNull == 0)
      {
         cin.ignore();
         cin.getline(word, 256);
      }
      else if (pNull > 0)
         cin.getline(word, 256);
   }
}

/*************************************************************************
* main() runs the program
*************************************************************************/
int main()
{
   char fileName[256];
   char word[1024][32];
   getFile(fileName);
   readFile(fileName, word);
   cout << "Thank you for playing.\n";

   return 0;
}