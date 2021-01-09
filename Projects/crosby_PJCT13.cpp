/*************************************************************************
* Program:
*    Project 13, Sudoku
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    The final part of the Sudoku Program project is to enforce the rules 
*    of Sudoku. This means that there can be only one instance of a given 
*    number on a row, column, or inside square.
*
*    Estimated:  10.0 hrs   
*    Actual:     10.0 hrs
* 
*      When I tried to execute the refinements that Bro Foushee suggested
*      to me on Project 12, I struggled to get everything to work right
*      to pass the testBed. Making the changes took ended up taking about
*      an extra hour or so.
*************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/*************************************************************************
* Prototypes
*************************************************************************/
void getFile(char theFile[]);
void readFile(char theFile[], int theBoard[][9]);
void engageUser(int theBoard[][9]);
void displayBoard(int theBoard[][9]);
void modifySquare(int theBoard[][9]);
void computeValues(int theBoard[][9], int row, char col);
void displayPossible(int theBoard[][9]);
void getSaveFile(char theFile[]);
void saveFile(char theFile[], const int theBoard[][9]);
void possibleSolves(int theBoard[][9], int array[], int row, char col);
bool verify(int theBoard[][9], int r, int c, int numCheck);
bool confirm(int theBoard[][9], int r, int c, int value);

/*************************************************************************
* main() calls getFile(), readFile(), engageUser(), getSaveFile(), and 
* saveFile(). Ie executes the program.
*************************************************************************/
int main()
{
   char theFile[256];
   int theBoard[9][9];

   getFile(theFile);
   readFile(theFile, theBoard);
   engageUser(theBoard);
   getSaveFile(theFile);
   saveFile(theFile, theBoard);

   return 0;
}

/*************************************************************************
* getFile() will prompt user to input the file name
*************************************************************************/
void getFile(char theFile[])
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
      cout << "Error reading file \"" << theFile << "\"\n";
      return;
   }

   for (int row = 0; row < 9; row++)
   {
      for (int col = 0; col < 9; col++)
         fin >> theBoard[row][col];
   }
   // Close the file
   fin.close();
}

/*************************************************************************
* engageUser() displays board instructions and allows user to select the
* next desire action
*************************************************************************/
void engageUser(int theBoard[][9])
{
   bool quit = false;
   char option;

   // Display instructions to the user
   cout << "Options:\n";
   cout << "   ?  Show these instructions\n";
   cout << "   D  Display the board\n";
   cout << "   E  Edit one square\n";
   cout << "   S  Show the possible values for a square\n";
   cout << "   Q  Save and Quit\n\n";

   // Display the board at the start of engagement
   displayBoard(theBoard);
   do
   {
      cout << "> ";
      cin >> option;

      switch (option)
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
            modifySquare(theBoard);
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
* displayBoard() displays the board to the user
*************************************************************************/
void displayBoard(int theBoard[][9])
{
   // Header for each board
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
* updateBoard() prompts the user to input value changes
*************************************************************************/
void modifySquare(int theBoard[][9])
{
   int row;
   char col;
   cout << "What are the coordinates of the square: ";
   cin >> col >> row;
   computeValues(theBoard, row, col);

   return;
}

/*************************************************************************
* computeValues() will determines if the user can change the desired
* number or if there is already a number in position
*************************************************************************/
void computeValues(int theBoard[][9], int row, char col)
{
   int c = (static_cast < int > (col) - 65);
   int r = row - 1;
   int value;

   // If value is zero the user can input another number
   if (theBoard[row - 1][c] != 0)
   {
      cout << "ERROR: Square \'" << col << row << "\' is filled\n";
   }
   else
   {
      cout << "What is the value at \'" << col << row << "\': ";
      cin >> value;
      if (confirm(theBoard, r, c, value) == true)
      {
         theBoard[row - 1][c] = value;
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
   int arrayValue = 0;

   cout << "What are the coordinates of the square: ";
   cin >> col >> row;

   possibleSolves(theBoard, array, row, col);

   cout << "The possible values for \'" << col << row << "\' are: ";

   for (int value = 0; value < 9; value++)
   {
      if (array[value] == 1 || array[value] == 2 || array[value] == 3 ||
          array[value] == 4 || array[value] == 5 || array[value] == 6 ||
          array[value] == 7 || array[value] == 8 || array[value] == 9)
         arrayValue++;
      else;
   }

   for (int j = 0; j < arrayValue; j++)
   {
      if (j != arrayValue - 1)
      {
         cout << array[j] << ", ";
      }
      else
         cout << array[j] ;
   }
   cout << endl << endl;
}

/*************************************************************************
* getSaveFile() asks the user for the file name to save the square data
*************************************************************************/
void getSaveFile(char theFile[])
{
   cout << "What file would you like to write your board to: ";
   cin >> theFile;
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

   // Saves all data to new file 
   for (int row = 0; row < 9; row++) 
   {
      for (int col = 0; col < 9; col++)
         fout << theBoard[row][col] << " ";
   }

   // Close the file 
   fout.close();

   cout << "Board written successfully\n";

   return;
}

/*************************************************************************
* possibleSolve() will verify all rows and columns and call verify()
*************************************************************************/
void possibleSolves(int theBoard[][9], int array[], int row, char col)
{
   bool number = true;  
   bool numRow = true;
   bool numCol = true;
   int c = (static_cast < int > (col) - 65);
   int r = row - 1;
   int numCheck = 1;
   int start = 0;

   for (int count = 0; count < 9; count++)
   {
      for (int i = 0; i < 9; i++) //checking if same number in row
      {
         if (theBoard[r][i] == numCheck)
            numRow = false;
      }

      for (int j = 0; j < 9; j++)
      {
         if (theBoard[j][c] == numCheck) //checking if same number in column
            numCol = false;
      }
      //calling function to cycle through the square for all numbers from 1-9
      number = verify(theBoard, r, c, numCheck);
      //each must be true in order for the number to be added to the array
      if (number == true && numRow == true && numCol == true)
      {
         array[start] = numCheck;
         numCheck++;
         start++;
      }
      else
         numCheck++;

      number = true;
      numRow = true;
      numCol = true;
   }
}

/*************************************************************************
* verify() will cycle through board to determine if the number the user
* inputed is viable or return false if it is not
*************************************************************************/
bool verify(int theBoard[][9], int r, int c, int numCheck)
{
   int squareRow;
   int squareCol;
   bool number = true;

   if (c <= 2)
      squareCol = 0;
   else if (c <= 5)
      squareCol = 3;
   else if (c <= 8)
      squareCol = 6;

   if (r <= 2)
      squareRow = 0;
   else if (r <= 5)
      squareRow = 3;
   else if (r <= 8)
      squareRow = 6;

   int rowLimit = squareRow + 3;
   int colLimit = squareCol + 3;

   for (squareRow; squareRow < rowLimit; squareRow++)
   {
      for (squareCol; squareCol < colLimit; squareCol++)
      {
         if (theBoard[squareRow][squareCol] == numCheck)
         {
            number = false;
            return number;
         }
         else
            number = true;
      }
      squareCol -= 3;
   }
   return number;
}

/*************************************************************************
* confirm() will confirm if the specific number input fomr the user can
* remain in the designated location
*************************************************************************/
bool confirm(int theBoard[][9], int r, int c, int value)
{
   bool success = false;
   int squareRow;
   int squareCol;

   // Check if same number is in the row
   for (int i = 0; i < 9; i++)
   {
      if (theBoard[r][i] == value)
         return success;
   }

   // Check if the same number is in the column
   for (int j = 0; j < 9; j++)
   {
      if (theBoard[j][c] == value)
         return success;
   }

   // Check if the same number is in the square 
   if (c <= 2)
      squareCol = 0;
   else if (c <= 5)
      squareCol = 3;
   else if (c <= 8)
      squareCol = 6;

   if (r <= 2)   
      squareRow = 0;
   else if (r <= 5)
      squareRow = 3;
   else if (r <= 8)
      squareRow = 6;

   int rowLimit = squareRow + 3;
   int colLimit = squareCol + 3;

   // Cycle through the board
   for (squareRow; squareRow < rowLimit; squareRow++)
      for (squareCol; squareCol < colLimit; squareCol++)
      {
         if (theBoard[squareRow][squareCol] == value)
         {
            success = false;
            return success;
         }
         else
            success = true;
      }

   return success;
}