/************************************************************************
* Program:
*    Project 10, MadLib 
*    Brother Foushee, CS124
* Author:
*    Rellinxe Boni
* Summary:
*    This program will read in text from a file and prompt the user for 
*    input and rewrite the story of the text to display the story with
*    the user input.
*
*    Estimated:  10.0 hrs
*    Actual:     17.0 hrs
*      Everything was hard. I think the hardest part was getting the
*      spacing right as well as finding the right place to put cin.ignore()
*      because it kept grabbing a newline and erasing the first letter
*      of the user's input when it was being displayed.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;


/***********************************************************************
 * Prototypes
 ***********************************************************************/
void getFile(char fileName[]);
int readFile(char fileName[], char word[][32], int &replay);
void askQuestions(char word[], int tokenReveal, int &replay);
void displayStory(char word[][32], int tokenReveal);
bool playAgain(int &replay);

/***********************************************************************
 * getFile will get the file name from the user
 ***********************************************************************/
void getFile(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
}

/***********************************************************************
 * This function reads the file called then, call
 * askQuestions() to request the user's inputs
 ***********************************************************************/
int readFile(char fileName[], char word[][32], int &replay)
{
   ifstream fin;
   fin.open(fileName);
   if (fin.fail())
      cout << "Error reading file: " << fileName;

   int tokenReveal = 0;
   
   while (fin >> word[tokenReveal])
   {
      tokenReveal++;
   }
   fin.close();

   for (int i = 0; i < tokenReveal; i++)
   {
      if (word[i][0] == ':')
      {
         askQuestions(word[i], tokenReveal, replay);
      }
   }
   
   return tokenReveal;
}

/***********************************************************************
 * Will determine if the program needs to output a prompt to the user.
 ***********************************************************************/
void askQuestions(char word[],int tokenReveal, int &replay)
{
   if (isalpha(word[1]))
   {
      replay++;
      cout << "\t" << (char) toupper(word[1]);

      for (int i = 2; word[i]; i++)
      {
         if (word[i] == '_')
         {
            cout << " ";
         }
         else
         {
            cout << (char) tolower(word[i]);
         }
      }
      cout << ": ";

      if (replay <= 1)            
      {
         cin.ignore();                 
         cin.getline(word,32);        
      }
      else
      {
         cin.getline(word,32);
      }
   }
}

/***********************************************************************
 * This function requests the user for the MadLib's story Text
 ***********************************************************************/
void displayStory(char word[][32], int tokenReveal)
{
   cout << endl;

   for (int i = 0; i < tokenReveal; i++)
   { 
      if (word[i][0] == ':')
      {
         if (word[i][1] == '!')
         {
            cout << endl;
         }
         else if (word[i][1] == '<')
         {
            cout << '"';
         }
         else if (word[i][1] == '>')
         {
            if (word[i + 1][1] == '!')
            {
               cout << '"';
            }
            else
            {
               cout << "\" ";
            }
         }
         else if (word[i][1] == '.')
         {
            if (!isalpha(word[i + 1][0]))
            {
               cout << '.';
            }
            else
            {
               cout << ". ";
            }
         }
         else if (word[i][1] == ',')
         {
            if (!isalpha(word[i + 1][0]))
            {
               cout << ',';
            }
            else if (word[i + 1][0] == '\n')
            {
               cout << ',';
            }
            else
            {
               cout << ", ";
            }
         }
      }
      else if (!isalpha(word[i][0]) && isalpha(word[i][1]))
      {
         cout << ' ' << word[i] << ' ';
      }
      else if (isalpha(word[i][0]))
      {
         if (!isalpha(word[i + 1][0]))   //next item is punctuation
         {
            if (word[i + 1][1] == '<')
               cout << word[i] << ' ';
            else
               cout << word[i];
         }
         else
         {
            cout << word[i] << ' ';
         }
      }
      else                             // not alpha
      {
         if (!isalpha(word[i + 1][0]))
         {
            cout << word[i];
         }
         else
         {
            cout << word[i] << ' ';
         }
      }
   }
   cout << endl;
}


/***********************************************************************
 * Will ask user to play again if he wants.
 ***********************************************************************/
bool playAgain(int &replay)
{
   bool again;
   char answer;
   replay = 0;
   cout << "Do you want to play again (y/n)? ";
   cin >> answer;

   if (answer == 'y')
      again = true;
   else if (answer == 'n')
      again = false;
   else
   {
      cout << "Invalid entry. Do you want to play again (y/n)? ";
      cin >> answer;
   }
   return again;
}

/***********************************************************************
 * Main runs the program
 ***********************************************************************/
int main()
{
   char fileName[256];
   char word[1024][32];
   bool again = true;
   int count = 0; 

   do
   {
      getFile(fileName);
      int tokenReveal = readFile(fileName, word, count);
      displayStory(word, tokenReveal);
      again = playAgain(count);
   }
   while (again == true);  
      cout << "Thank you for playing.\n";
   
   return 0;
}




