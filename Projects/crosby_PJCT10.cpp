/*************************************************************************
* Program:
*    Project 10, MadLib
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
void getFile(char theFile[]);
int readFile(char theFile[], char theWord[][32], int &restart);
void askQuestions(char theWord[], int file, int &restart);
void displayStory(char theWord[][32], int file);
bool hitRestart(int &restart);

/*************************************************************************
 * getFile() method will recieve the file name from the user
*************************************************************************/
void getFile(char theFile[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> theFile;
}

/*************************************************************************
 * readFile() method will read file received and call askQuestions()
*************************************************************************/
int readFile(char theFile[], char theWord[][32], int &restart)
{
   ifstream fin;
   fin.open(theFile);
   if (fin.fail())
      cout << "Error reading file: " << theFile;

   int file = 0;
   
   while (fin >> theWord[file])
   {
      file++;
   }
   fin.close();

   for (int i = 0; i < file; i++)
   {
      if (theWord[i][0] == ':')
      {
         askQuestions(theWord[i], file, restart);
      }
   }
   
   return file;
}

/*************************************************************************
 * askQuestions() method will prompt user for input if necessary
*************************************************************************/
void askQuestions(char theWord[],int file, int &restart)
{
   if (isalpha(theWord[1]))
   {
      restart++;
      cout << "\t" << (char) toupper(theWord[1]);

      for (int i = 2; theWord[i]; i++)
      {
         if (theWord[i] == '_')
         {
            cout << " ";
         }
         else
         {
            cout << (char) tolower(theWord[i]);
         }
      }
      cout << ": ";

      if (restart <= 1)            
      {
         cin.ignore();                 
         cin.getline(theWord,32);        
      }
      else
      {
         cin.getline(theWord,32);
      }
   }
}

/*************************************************************************
 * displayStory() method will display madlib story
*************************************************************************/
void displayStory(char theWord[][32], int file)
{
   cout << endl;

   for (int i = 0; i < file; i++)
   { 
      if (theWord[i][0] == ':')
      {
         if (theWord[i][1] == '!')
         {
            cout << endl;
         }
         else if (theWord[i][1] == '<')
         {
            cout << '"';
         }
         else if (theWord[i][1] == '>')
         {
            if (theWord[i + 1][1] == '!')
            {
               cout << '"';
            }
            else
            {
               cout << "\" ";
            }
         }
         else if (theWord[i][1] == '.')
         {
            if (!isalpha(theWord[i + 1][0]))
            {
               cout << '.';
            }
            else
            {
               cout << ". ";
            }
         }
         else if (theWord[i][1] == ',')
         {
            if (!isalpha(theWord[i + 1][0]))
            {
               cout << ',';
            }
            else if (theWord[i + 1][0] == '\n')
            {
               cout << ',';
            }
            else
            {
               cout << ", ";
            }
         }
      }
      else if (!isalpha(theWord[i][0]) && isalpha(theWord[i][1]))
      {
         cout << ' ' << theWord[i] << ' ';
      }
      else if (isalpha(theWord[i][0]))
      {
         if (!isalpha(theWord[i + 1][0]))
         {
            if (theWord[i + 1][1] == '<')
               cout << theWord[i] << ' ';
            else
               cout << theWord[i];
         }
         else
         {
            cout << theWord[i] << ' ';
         }
      }
      else                             
      {
         if (!isalpha(theWord[i + 1][0]))
         {
            cout << theWord[i];
         }
         else
         {
            cout << theWord[i] << ' ';
         }
      }
   }
   cout << endl;
}

/*************************************************************************
 * hitRestart prompts the user if they want to restart the game
*************************************************************************/
bool hitRestart(int &restart)
{
   bool redo;
   char yesNo;
   restart = 0;
   cout << "Do you want to play again (y/n)? ";
   cin >> yesNo;

   if (yesNo == 'y')
      redo = true;
   else if (yesNo == 'n')
      redo = false;
   else
   {
      cout << "Invalid entry. Do you want to play again (y/n)? ";
      cin >> yesNo;
   }
   return redo;
}

/*************************************************************************
 * main() calls all the functions and executes the program
*************************************************************************/
int main()
{
   char theFile[256];
   char theWord[1024][32];
   bool restart = true;
   int count = 0; 

   do
   {
      getFile(theFile);
      int file = readFile(theFile, theWord, count);
      displayStory(theWord, file);
      restart = hitRestart(count);
   }
   while (restart == true);  
      cout << "Thank you for playing.\n";
   
   return 0;
}
