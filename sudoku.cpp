/***********************************************************************
* Program:
*    Project 13, Sudoku
*    Brother Foushee, CS124
* Author:
*    Rellinxe Boni
* Summary:
*    This final SUDOKU program will display a sudoku board and allow 
*    interaction with the user.
*
*    Estimated:  3.0 hrs
*    Actual:     15.0 hrs
*      I kinda messed up with project13 while trying to edit project 12 which
*      caused me to get stuck on my code. Try to fix the bugs and write the 
*      updates were very hard. 
************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

/************************************************************************
* Prototypes
************************************************************************/
void currentFile(char filename[]);
void readFile(char filename[], int board[][9]);
void interact(int board[][9]);
void displayBoard(int board[][9]);
void editSquare(int board[][9]);
void computeValues(int board[][9], int row, char col);
void displayPossibleValues(int board[][9]);
void getFileName(char filename[]);
bool check(int board[][9], int x, int y, int value);
void possibleValue(int board[][9], int array[], int row, char col);
bool verifySquare(int board[][9], int x, int y, int numberCheck);
void saveBoard(char filename[], const int board[][9]);


/************************************************************************
* This will prompt the user for the fileName
************************************************************************/
void currentFile(char filename[])
{
   cout << "Where is your board located? ";
   cin >> filename;
}

/************************************************************************
* This will read the file input by the user and store it into 
* multidimentional array board
************************************************************************/
void readFile(char filename[], int board[][9])
{
   ifstream fin(filename);
   if (fin.fail())
   {
      cout << "Error reading file " << filename << endl;
      return;
   }

   for (int row = 0; row < 9; row++)
   {
      for (int col = 0; col < 9; col++)
         fin >> board[row][col];
   }
   fin.close(); //close the file
}

/************************************************************************
* This will display the board
************************************************************************/
void displayBoard(int board[][9])
{
   cout << "   A B C D E F G H I\n"; //Header to display on each board
   
   int count = 1; 
                      //to show which number row
   for (int row = 0; row < 9; row++)
   {
      cout << count << "  ";         //show count and space after each row
      for (int col = 0; col < 9; col++)
      {
         if (board[row][col] == 0)   // all zeros will be a space on the board
            cout << " ";
         else
            cout << board[row][col]; //if not zero put number on board

         if (col == 2 || col == 5)
            cout << "|";             // this will separate quadrants
         else
         {
            if (col == (9 - 1))   //end of row
               cout << endl;
            else
               cout << " ";
         }
      }
      if (row == 2 || row == 5)
         cout << "   -----+-----+-----\n";
      count++;                       //increase row number
   }
   cout << endl;
}

/**********************************************************************
* Display the instruction and prompt user to pick a desired option
***********************************************************************/
void interact(int board[][9])
{
   bool quit = false;
   char prompt;
   
   cout << "Options:\n"; //have to show instruction on initial load
   cout << "   ?  Show these instructions\n";
   cout << "   D  Display the board\n";
   cout << "   E  Edit one square\n";
   cout << "   S  Show the possible values for a square\n";
   cout << "   Q  Save and Quit\n\n";
   displayBoard(board); //also have to display board on initial load
   do
   {
      cout << "> "; //will put carrot after each iteration
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
            displayBoard(board);
            break;
         case 'e':
         case 'E':
            editSquare(board);
            break;
         case 'q':
         case 'Q':
            quit = true;
            break;
         case 's':
         case 'S':
            displayPossibleValues(board);
            break;
      }
   } while (quit == false);

   return;
}


/************************************************************************
* This function will make the  user to edit a square
************************************************************************/
void editSquare(int board[][9])
{
   int row;
   char col;
   
   cout << "What are the coordinates of the square: ";
   cin >> col >> row;             //get row and column from user
   computeValues(board, row, col);

   return;
}

/**********************************************************************
* This will take coordinates that user wants to change and determine
* if there is currently a number in position. If no number then user will
* be asked to enter a number.
***********************************************************************/
void computeValues(int board[][9], int row, char col)
{
   int y = (static_cast<int>(col) - 65); //casting char to int
   int x = row - 1;
   int value;                               

   if (board[row - 1][y] != 0)           //If zero, then user can replace with
   {                                        //another number
      cout << "ERROR: Square \'" << col << row << "\' is filled\n";
   }
   else
   {
      cout << "What is the value at \'" << col << row << "\': ";
      cin >> value;
      if (check(board, x, y, value) == true)
      {
         board[row - 1][y] = value;
      }
      else
      {
         cout << "ERROR: Value \'" << value << "\' in square \'" << col << row;
         cout << "\' is invalid\n";
      }
   }
   cout << endl;

   return;
}

/**********************************************************************
* This function start function to determine possible values in a given
* square. It will display the options to the user. 
***********************************************************************/
void displayPossibleValues(int board[][9])
{
   int row;
   char col;
   int array[9];
   int arrayS = 0;
   cout << "What are the coordinates of the square: ";
   cin >> col >> row;             //get row and column from user
   possibleValue(board, array, row, col);

   cout << "The possible values for \'" << col << row << "\' are: ";

   for (int length = 0; length < 9; length++) //This will check all locations in
   {                                       //the array for a number from 1-9
      if (array[length] == 1 || array[length] == 2 || array[length] == 3 ||
          array[length] == 4 || array[length] == 5 || array[length] == 6 ||
          array[length] == 7 || array[length] == 8 || array[length] == 9)
         arrayS++;
      else
         ;
   }

   for (int j = 0; j < arrayS; j++)
   {
      if (j != arrayS - 1)
      {
         cout << array[j] << ", ";
      }
      else
         cout << array[j] ;
   }
   cout << endl << endl;
}

/************************************************************************
* This will prompt the user for the fileName
************************************************************************/
void getFileName(char filename[])
{
   cout << "What file would you like to write your board to: ";
   cin >> filename;
}

/**********************************************************************
* This will check if the user can input a specific number to a desired location
***********************************************************************/
bool check(int board[][9], int x, int y, int value)
{
   bool completed = false;
   int sqRow;
   int sqCol;
   //check if same number in row
   for (int i = 0; i < 9; i++)
   {
      if (board[x][i] == value)
         return completed;
   }

   //check if same number in column
   for (int j = 0; j < 9; j++)
   {
      if (board[j][y] == value)
         return completed;
   }

   //check in the square if there is the same number
   if (y <= 2)   // This will put the start of the square at the top left
      sqCol = 0;  //of every square. 
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

   //cycle through square
   for (sqRow; sqRow < rowLength; sqRow++)
      for (sqCol; sqCol < colLength; sqCol++)
      {
         if (board[sqRow][sqCol] == value)
         {
            completed = false;
            return completed;
         }
         else
            completed = true;
      }

   return completed;
}

/**********************************************************************
* This will check all rows and columns as well as call the square checking
* function
***********************************************************************/
void possibleValue(int board[][9], int array[], int row, char col)
{
   bool number = true;  
   bool numberCol = true;
   bool numberRow = true;
   int y = (static_cast<int>(col) - 65);
   int x = row - 1;
   int numberCheck = 1;
   int start = 0;

   for (int count = 0; count < 9; count++)
   {
      for (int i = 0; i < 9; i++) //checking if same number in row
      {
         if (board[x][i] == numberCheck)
            numberRow = false;
      }

      for (int j = 0; j < 9; j++)
      {
         if (board[j][y] == numberCheck) //checking if same number in column
            numberCol = false;
      }
      //calling function to cycle through the square for all numbers from 1-9
      number = verifySquare(board, x, y, numberCheck);
      //each must be true in order for the number to be added to the array
      if (number == true && numberRow == true && numberCol == true)
      {
         array[start] = numberCheck;
         numberCheck++;
         start++;
      }
      else
         numberCheck++;

      number = true;
      numberRow = true;
      numberCol = true;
   }
}

/**********************************************************************
* This will cycle through the square and determine if the user input number
* is a viable number and return true if it is or false is there already is
* the number in the selected block
***********************************************************************/
bool verifySquare(int board[][9], int x, int y, int numberCheck)
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
   //This will cycle through the entire square
   //and check if the selected number is a viable option
   for (sqRow; sqRow < rowLength; sqRow++)
   {
      for (sqCol; sqCol < colLength; sqCol++)
      {
         if (board[sqRow][sqCol] == numberCheck)
         {
            number = false;
            return number;
         }
         else
            number = true;
      }
      sqCol -= 3; //must turn the squareCol back 3 so that it starts from
                      //the initial column
   }
   return number;
}

/************************************************************************
* This function  will prompt the user to save the program.
************************************************************************/
void saveBoard(char filename[], const int board[][9])
{
   ofstream fout(filename);

   if (fout.fail())
   {
      cout << "Error writing to file \"" << filename << "\"\n";
      return;
   }

   for (int row = 0; row < 9; row++) // will write all data into new file. 
   {
      for (int col = 0; col < 9; col++)
         fout << board[row][col] << " "; //space after each number
   }
   fout.close(); //Close the file

   cout << "Board written successfully\n";

   return;
}

/************************************************************************
* Main will drive the program
************************************************************************/
int main()
{
   char filename[256];
   int board[9][9]; //current size is 9X9

   currentFile(filename); //Get file name
   readFile(filename, board);
   interact(board);
   getFileName(filename);
   saveBoard(filename, board);

   return 0;
}

