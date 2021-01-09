/*************************************************************************
* Program:
*    Project 13, Extra Credit
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

#define SIZE 9

/*************************************************************************
* checkBoard()  double checks the array board.
*************************************************************************/
bool checkBoard(int boardArray[][SIZE])
{
   int row = 0;
   int col = 0;
   char coords[2];

   for (int loop = 0; loop < SIZE; loop++)
   {
      int numCol[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      int numRow[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      int numBox[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      for (int r = 0; r < 9; r++)
      {
         if (boardArray[r][col] != 0)
            numCol[boardArray[r][col]] += 1;
         if (numCol[boardArray[r][col]] > 1)
         {
            coords[1] = r + 48;
            coords[0] = col + 66;
            cout << "ERROR: Duplicate value '" << boardArray[r][col]
                 << "' in inside square represented by '"
                 << coords[0] << coords[1] << "'\n";
            return false;
         }
      }
      for (int c = 0; c < 9; c++)
      {
         if (boardArray[row][c] != 0)
            numRow[boardArray[row][c]] += 1;
         if (numRow[boardArray[row][c]] > 1)
         {
            coords[1] = row + 48;
            coords[0] = c + 66;
            cout << "ERROR: Duplicate value '" << boardArray[row][c]
                 << "' in inside square represented by '"
                 << coords[0] << coords[1] << "'\n";
            return false;
         }
      }
      int mRow = (row / 3) * 3;
      int mCol = (col / 3) * 3;
      for (int r = mRow; r < (mRow + 3); r++)
      {
         for (int c = mCol; c < (mCol + 3); c++)
         {
            if (boardArray[r][c] != 0)
               numBox[boardArray[r][c]] += 1;
            if (numBox[boardArray[r][c]] > 1)
            {
               coords[1] = r + 48;
               coords[0] = c + 66;
               cout << "ERROR: Duplicate value '" << boardArray[r][c]
                    << "' in inside square represented by '"
                    << coords[0] << coords[1] << "'\n";
               return false;
            }
         }
      }
      row++;
      col++;
   }
   return true;
}

/*************************************************************************
* gettheFile() prompts user for the file name
*************************************************************************/
void getTheFile(char theFile[])
{
   cout << "Where is your board located? ";
   cin >> theFile;
   return;
}

/*************************************************************************
* createArray() transfers data from the file into an array.
*************************************************************************/
bool createArray(int boardArray[][SIZE], char theFile[],
                 bool boardArrayRO[][SIZE])
{
   bool validBoard = true;
   ifstream fin(theFile);
   if (fin.fail())
   {
      cout << "Unable to open file " << theFile << ".\n";
      return true;
   }
   // First loop parsing the rows.
   for (int row = 0; row < SIZE; row++)
   {
      // go through each column inputting info from thefile
      for (int col = 0; col < SIZE; col++)
      {
         fin >> boardArray[row][col];
         if (boardArray[row][col] != 0)
            boardArrayRO[row][col] = true;
         else
            boardArrayRO[row][col] = false;
      }
   }
   fin.close();
   validBoard = checkBoard(boardArray);
   if (!validBoard)
      return true;
   return false;
}

/*************************************************************************
* drawBoard() stores arrays and calls other functions.
*************************************************************************/
void drawBoard(int boardArray[][SIZE], bool boardArrayRO[][SIZE])
{
   cout << "   A B C D E F G H I\n";
   // First loop parsing the rows
   for (int row = 0; row < SIZE; row++)
   {
      cout << row + 1 << "  ";
      
      // go through each row inputting info from thefile
      for (int col = 0; col < SIZE; col++)
      {
         // if array is 0 input blank
         if (boardArray[row][col] == 0)
            cout << " ";
         else
         {
            if (boardArrayRO[row][col])
               cout << "\E[22;32m" << boardArray[row][col] << "\E[0m";
            else
               cout << boardArray[row][col];
         }
         
         if ((col + 1) % 3 != 0)
            cout << " ";
         
         else if (col == (SIZE - 1))
            cout << endl;
         
         else
            cout << '|';
      }
      
      if (row == 2 || row == 5)
         cout << "   -----+-----+-----\n";
   }
   cout << "\n";
}

/*************************************************************************
* displayMenu() This function displays the options menu.
*************************************************************************/
void displayMenu()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n\n";
   return;
}

/*************************************************************************
 * Check for valid coordinate data.
 ************************************************************************/
bool isValid(char coords[])
{
   // Make sure the letter is an alpha and the number is a digit
   if (isalpha(coords[0]) && isdigit(coords[1]))
   {
      // Letter needs to be between A and I.
      if (coords[0] >= 'A' && coords[0] <= 'I')
      {
         // Numbers 1 through 9 only
         if (coords[1] >= '1' && coords[1] <= '9')
         {
            return true;
         }
      }
   }
   return false;
}

/*************************************************************************
* promptNum() prompts user for an input number
*************************************************************************/
int promptNum(char coords[])
{
   int inputNum;
   cout << "What is the value at '" << coords[0] << coords[1] << "': ";
   cin >> inputNum;

   // musr be between 1 and 9.
   if (inputNum < 1 || inputNum > SIZE)
   {
      cout << "ERROR: Value '" << inputNum << "' in square '"
           << coords[0] << coords[1] << "' is invalid\n\n";
      return 0;
   }
   return inputNum;
}

/*************************************************************************
* checkEmpty() checks if square is empty
*************************************************************************/
bool checkEmpty(int boardArray[][SIZE], int row, int col)
{
   if (boardArray[row][col] == 0)
      return true;
   else
      return false;
}

/*************************************************************************
* getCoords () prompts user for coordinates to input
*************************************************************************/
bool getCoords (char coords[], int boardArray[][SIZE],
                bool boardArrayRO[][SIZE])
{
   int row = 0;
   int col = 0;
   char tempCoords[2];
   bool loop = true;
   do
   {
      cout << "What are the coordinates of the square: ";
      cin >> tempCoords[0] >> tempCoords[1];
      if (isalpha(tempCoords[1]))
      {
         coords[0] = tempCoords[1];
         coords[1] = tempCoords[0];
      }
      else
      {
         coords[0] = tempCoords[0];
         coords[1] = tempCoords[1];
      }
      
      if (islower(coords[0]))
         coords[0] = toupper(coords[0]);

      // Convert the user input into array
      col = coords[0] - 65;
      row = coords[1] - 49;
      if (!isValid(coords))
      {
         cout << "ERROR: Square '" << tempCoords[0] << tempCoords[1]
              << "' is invalid\n";
      }
      else if (!checkEmpty(boardArray,row,col) && boardArrayRO[row][col])
      {
         cout << "ERROR: Square '"
              << coords[0] << coords[1] << "' is read-only\n\n";
         return false;
      }
      else
         loop = false;
   }
   while (loop);
   return true;
}

/*************************************************************************
* getValues() shows user for available values in the squares
*************************************************************************/
void getValues(int boardArray[][SIZE], char coords[], bool values[])
{
   // convert coordiantes to corresponding col and row
   int numCol = coords[0] - 'A';
   int numRow = coords[1] - '1';
   
   for (int iTrue = 1; iTrue < 10; iTrue++)
   {
      values[iTrue] = true;
   }
   // verify any already used numbers in row
   for (int r = 0; r < 9; r++)
   {
      if (r != numRow)
         values[ boardArray[r][numCol] ] = false;
   }
   // verify any already used numbers in column
   for (int c = 0; c < 9; c++)
   {
      if (c != numCol)
         values[ boardArray[numRow][c] ] = false;
   }
   
   int mRow = (numRow / 3) * 3;
   int mCol = (numCol / 3) * 3;
   for (int r = mRow; r < (mRow + 3); r++)
   {
      for (int c = mCol; c < (mCol + 3);c++)
      {
         if (r != numCol || c != numRow)
            values[boardArray[r][c]] = false;
      }
   }
      
   return;
}

/*************************************************************************
* editArray() modifiys coordinates on the board
*************************************************************************/
void editArray(int boardArray[][SIZE], bool boardArrayRO[][SIZE])
{
   bool values[10];
   char coords[2];
   int inputNum;
   int col;
   int row;
   if (getCoords(coords,boardArray,boardArrayRO))
   {
      // Convert the user input to corresponding into array
      col = coords[0] - 65;
      row = coords[1] - 49;
      // Get new number from the user.
      inputNum = promptNum(coords);
      if (inputNum != 0)
      {
         // confirm availability of input number
         getValues(boardArray,coords,values);
         if (values[inputNum])
         {
            boardArray[row][col] = inputNum;
            cout << endl;
            return;
         }
         else
         {
            cout << "ERROR: Value '" << inputNum
                 << "' in square '" << coords[0] << coords[1]
                 << "' is invalid\n\n";
            return;
         }
      }
      else
         return;
   }
}

/*************************************************************************
* showOptions() shows user available options
*************************************************************************/
void showOptions(int boardArray[][SIZE], bool boardArrayRO[][SIZE])
{
   bool values[10];
   char coords[2];
   if (getCoords(coords,boardArray,boardArrayRO))
   {
      int numCol = coords[0] - 'A';
      int numRow = coords[1] - '1';
      getValues(boardArray,coords,values);
      if (checkEmpty(boardArray,numRow,numCol))
      {
         cout << "The possible values for '"
              << coords[0] << coords[1]
              << "' are: ";
         int iTrue = 0;
         for (int iCount = 1; iCount <= 9; iCount++)
         {
            if (values[iCount])
               
               iTrue += 1;
         }
         for (int iValues = 1; iValues <= 9; iValues++)
         {
            if (values[iValues]) // if true display the result
            {
               cout << iValues;
               iTrue -= 1;
               if (iTrue > 0)
                  cout << ", ";
               else
                  
                  cout << endl;
            }
         }
         cout << "\n";
      }
      else
         cout << "It is filled\n";
   }
   else if (!getCoords(coords,boardArray,boardArrayRO))
   {
      cout << "Error!\n";
   }

   return;
}

/*************************************************************************
* saveAndQuit() prompts to save and the returns quit.
*************************************************************************/
bool saveAndQuit(int boardArray[][SIZE])
{
   char theFile[256];
   cout << "What file would you like to write your board to: ";
   cin >> theFile;
   ofstream fout(theFile);
   // Check for issues opening file.
   if (fout.fail())
   {
      cout << "Unable to open file " << theFile
           << "." << endl;
      return false;
   }
   // First loop parsing the rows
   for (int row = 0; row < SIZE; row++)
   {
      // For each row we go through the columns input info
      // from our array to the file.
      for (int col = 0; col < SIZE; col++)
      {
         if (col != (SIZE - 1))
            fout << boardArray[row][col] << " ";
         else
            fout << boardArray[row][col] << endl;
      }
   }
   cout << "Board written successfully\n";
   fout.close();
   return false;
}

/*************************************************************************
* interact() engages the user for input
*************************************************************************/
void interact(int boardArray[][SIZE], bool boardArrayRO[][SIZE])
{
   char userInput;
   bool stayInLoop = true;
   displayMenu();
   drawBoard(boardArray,boardArrayRO);
   do
   {
      cout << "> ";
      cin >> userInput;
      switch (userInput)
      {
         case '?':
            displayMenu();
            cout << endl;
            break;
         case 'D':
         case 'd':
            drawBoard(boardArray,boardArrayRO);
            break;
         case 'E':
         case 'e':
            editArray(boardArray,boardArrayRO);
            break;
         case 'S':
         case 's':
            showOptions(boardArray,boardArrayRO);
            break;
         case 'Q':
         case 'q':
            stayInLoop = saveAndQuit(boardArray);
            break;
         default:
            cout << "ERROR: Invalid command\n\n";
      }
   }
   while (stayInLoop);
   return;
}

/*************************************************************************
* main() drives the program
*************************************************************************/
int main()
{
   char theFile[256];
   int boardArray[SIZE][SIZE];
   
   bool boardArrayRO[SIZE][SIZE];
   getTheFile(theFile);
   if (createArray(boardArray,theFile,boardArrayRO))
      return 0;
   interact(boardArray,boardArrayRO);
   return 0;
}