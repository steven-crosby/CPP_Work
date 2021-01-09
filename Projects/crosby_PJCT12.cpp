/*************************************************************************
* Program:
*    Project 12, Sudoku
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    The second part of the Sudoku Program project (the first part being 
*    the design document due earlier) is to write the code necessary to 
*    make the Sudoku appear on the screen and to allow some simple 
*    interactions.
*
*    Estimated:  12.0 hrs   
*    Actual:     12.0 hrs
*      Please describe briefly what was the most difficult part.
*************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

/*************************************************************************
* Prototypes
*************************************************************************/
void workingFile(char theFile[]);
void readFile(char theFile[], int theBoard[][9]);
void engageUser(int theBoard[][9]);
void displayBoard(int theBoard[][9]);
void updateBoard(int theBoard[][9]);
void computeSolves(int theBoard[][9], int row, char col);
void displayPossible(int theBoard[][9]);
void getFile(char theFile[]);
bool confirm(int theBoard[][9], int x, int y, int value);
void possibleSolve(int theBoard[][9], int array[], int row, char col);
bool verify(int theBoard[][9], int x, int y, int numberCheck);
void saveFile(char theFile[], const int theBoard[][9]);

/************************************************************************
* main() executes the whole program
************************************************************************/
int main()
{
   char theFile[256];
   int theBoard[9][9];

   workingFile(theFile);
   readFile(theFile, theBoard);
   engageUser(theBoard);
   getFile(theFile);
   saveFile(theFile, theBoard);

   return 0;
}

/*************************************************************************
* workingFile() asks the user for the file name
*************************************************************************/
void workingFile(char theFile[])
{
   cout << "Where is your board located? ";
   cin >> theFile;
}

/*************************************************************************
* readFile() will read the file inputed by the user and store in the array
*************************************************************************/
void readFile(char theFile[], int theBoard[][9])
{
   ifstream fin(theFile);
   if (fin.fail())
   {
      cout << "Error reading file " << theFile << endl;
      return;
   }

   for (int row = 0; row < 9; row++)
   {
      for (int col = 0; col < 9; col++)
         fin >> theBoard[row][col];
   }
   // close thefile
   fin.close();
}

/*************************************************************************
* displayBoard() displays the board to the user
*************************************************************************/
void displayBoard(int theBoard[][9])
{
   // the header for the board
   cout << "   A B C D E F G H I\n";
   
   int count = 1; 
   for (int row = 0; row < 9; row++)
   {
      cout << count << "  ";
      for (int col = 0; col < 9; col++)
      {
         if (theBoard[row][col] == 0)
            cout << " ";
         else
            cout << theBoard[row][col];

         if (col == 2 || col == 5)
            cout << "|";
         else
         {
            if (col == (9 - 1))
               cout << endl;
            else
               cout << " ";
         }
      }
      if (row == 2 || row == 5)
         cout << "   -----+-----+-----\n";
      count++;
   }
   cout << endl;
}

/*************************************************************************
* engageUser() displays board instructions and allows user to select the
* next desire action
*************************************************************************/
void engageUser(int theBoard[][9])
{
   bool quit = false;
   char prompt;
   
   // display instructions at start
   cout << "Options:\n";
   cout << "   ?  Show these instructions\n";
   cout << "   D  Display the board\n";
   cout << "   E  Edit one square\n";
   cout << "   S  Show the possible values for a square\n";
   cout << "   Q  Save and Quit\n\n";

   // display board at start
   displayBoard(theBoard);
   do
   {
      cout << "> ";
      cin >> prompt;

      switch (prompt)
      {
         case '?':
            cout << "Options:\n";
            cout << "   ?  Show these instructions\n";
            cout << "   D  Display the board\n";
            cout << "   E  Edit one square\n";
            cout << "   S  Show the possible values for a square\n";
            cout << "   Q  Save and Quit\n\n";
            cout << endl;
            break;
         case 'd':
         case 'D':
            displayBoard(theBoard);
            break;
         case 'e':
         case 'E':
            updateBoard(theBoard);
            break;
         case 'q':
         case 'Q':
            quit = true;
            break;
         case 's':
         case 'S':
            displayPossible(theBoard);
            break;
      }
   } while (quit == false);

   return;
}

/*************************************************************************
* updateBoard() prompts the user to input changes
*************************************************************************/
void updateBoard(int theBoard[][9])
{
   int row;
   char col;
   
   cout << "What are the coordinates of the square: ";
   cin >> col >> row;
   computeSolves(theBoard, row, col);

   return;
}

/*************************************************************************
* computeSolves() will determines if the user can change the desired
* number or if there is already a number in position
*************************************************************************/
void computeSolves(int theBoard[][9], int row, char col)
{
   int y = static_cast < int > (col) - 65;
   int x = row - 1;
   int value;                               

   if (theBoard[row - 1][y] != 0)
   {
      cout << "ERROR: Square \'" << col << row << "\' is filled\n";
   }
   else
   {
      cout << "What is the value at \'" << col << row << "\': ";
      cin >> value;
      if (confirm(theBoard, x, y, value) == true)
      {
         theBoard[row - 1][y] = value;
      }
      else
      {
         cout << "ERROR: Value \'" 
            << value 
            << "\' in square \'"
            << col 
            << row;
         cout << "\' is invalid\n";
      }
   }
   cout << endl;

   return;
}

/*************************************************************************
* displayPossible() determines possible solves in the square and will
* display possible solves to the user
*************************************************************************/
void displayPossible(int theBoard[][9])
{
   int row;
   char col;
   int array[9];
   int pArray = 0;
   cout << "What are the coordinates of the square: ";
   cin >> col >> row;
   possibleSolve(theBoard, array, row, col);

   cout << "The possible values for \'" << col << row << "\' are: ";

   // double checks all locations in array for numbers 1-9
   for (int length = 0; length < 9; length++)
   {
      if (array[length] == 1 || array[length] == 2 || array[length] == 3 ||
          array[length] == 4 || array[length] == 5 || array[length] == 6 ||
          array[length] == 7 || array[length] == 8 || array[length] == 9)
         pArray++;
      else
         ;
   }

   for (int j = 0; j < pArray; j++)
   {
      if (j != pArray - 1)
      {
         cout << array[j] << ", ";
      }
      else
         cout << array[j] ;
   }
   cout << endl << endl;
}

/*************************************************************************
* getFile() asks the user for the file name
*************************************************************************/
void getFile(char theFile[])
{
   cout << "What file would you like to write your board to: ";
   cin >> theFile;
}

/*************************************************************************
* confirm() will confirm if the user can input their desired number
*************************************************************************/
bool confirm(int theBoard[][9], int x, int y, int value)
{
   bool completed = false;
   int sqRow;
   int sqCol;
   
   // Confirm if the same number is in the row
   for (int i = 0; i < 9; i++)
   {
      if (theBoard[x][i] == value)
         return completed;
   }

   // Confirm if the same number in column
   for (int j = 0; j < 9; j++)
   {
      if (theBoard[j][y] == value)
         return completed;
   }

   // Confirm if there is the same number
   if (y <= 2)
      sqCol = 0;
   else if (y <= 5)
      sqCol = 3;
   else if (y <= 8)
      sqCol = 6;

   if (x <= 2)
      sqRow = 0;
   else if (x <= 5)
      sqRow = 3;
   else if (x <= 8)
      sqRow = 6;

   int rowLength = sqRow + 3;
   int colLength = sqCol + 3;

   //Cycle through the square
   for (sqRow; sqRow < rowLength; sqRow++)
      for (sqCol; sqCol < colLength; sqCol++)
      {
         if (theBoard[sqRow][sqCol] == value)
         {
            completed = false;
            return completed;
         }
         else
            completed = true;
      }

   return completed;
}

/*************************************************************************
* possibleSolve() will verify all rows and columns and call verify()
*************************************************************************/
void possibleSolve(int theBoard[][9], int array[], int row, char col)
{
   bool number = true;  
   bool numberCol = true;
   bool numberRow = true;
   int y = static_cast < int > (col) - 65;
   int x = row - 1;
   int numCheck = 1;
   int start = 0;

   for (int count = 0; count < 9; count++)
   {
      for (int i = 0; i < 9; i++) //checking if same number in row
      {
         if (theBoard[x][i] == numCheck)
            numberRow = false;
      }

      for (int j = 0; j < 9; j++)
      {
         if (theBoard[j][y] == numCheck) //checking if same number in column
            numberCol = false;
      }
      //calling function to cycle through the square for all numbers from 1-9
      number = verify(theBoard, x, y, numCheck);
      //each must be true in order for the number to be added to the array
      if (number == true && numberRow == true && numberCol == true)
      {
         array[start] = numCheck;
         numCheck++;
         start++;
      }
      else
         numCheck++;

      number = true;
      numberRow = true;
      numberCol = true;
   }
}


/*************************************************************************
* verify() will check the user input to make sure its a viable number
*************************************************************************/
bool verify(int theBoard[][9], int x, int y, int numCheck)
{
   int sqRow;
   int sqCol;
   bool number = true;

   if (y <= 2)
      sqCol = 0;
   else if ( y <= 5)
      sqCol = 3;
   else if (y <= 8)
      sqCol = 6;

   if (x <= 2)
      sqRow = 0;
   else if (x <= 5)
      sqRow = 3;
   else if ( x <= 8)
      sqRow = 6;

   int rowLength = sqRow + 3;
   int colLength = sqCol + 3;

   // cycles through the square to verify
   // viability of numbers
   for (sqRow; sqRow < rowLength; sqRow++)
   {
      for (sqCol; sqCol < colLength; sqCol++)
      {
         if (theBoard[sqRow][sqCol] == numCheck)
         {
            number = false;
            return number;
         }
         else
            number = true;
      }
      sqCol -= 3; 
   }
   return number;
}

/*************************************************************************
* saveFile() prompts user to save the board
*************************************************************************/
void saveFile(char theFile[], const int theBoard[][9])
{
   ofstream fout(theFile);

   if (fout.fail())
   {
      cout << "Error writing to file \"" << theFile << "\"\n";
      return;
   }

   for (int row = 0; row < 9; row++)
   {
      for (int col = 0; col < 9; col++)
         fout << theBoard[row][col] << " ";
   }
   // Close thefile
   fout.close(); 

   cout << "Board written successfully\n";

   return;
}

