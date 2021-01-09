/***********************************************************************
* Program:
*    Project Extra, Sudoku
*    Brother Schwieder, CS124
* Author:
*    Christian Soldevilla
* Summary: 
*    This program is extra credit Project.
*
*    Estimated:  2 hrs   
*    Actual:     4 hrs
*      I had a lot of issues writing the chekBoard() function and figuring
*      out  how to validate all the functions.
************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

const string green("\033[1;32m");       // Const for color green
const std::string reset("\033[0m");     // Const for reset color

#define MAX    256                      // Used for char Arrays
#define SUDOKU   9                      // Maximum array size for board


void getFileName                                      (char fileName[MAX]);
void readFile                    (int board[][SUDOKU], char fileName[MAX]);
void displayOptions                                  (int board[][SUDOKU]);
void displayBoard                                    (int board[][SUDOKU]);
void interact                                        (int board[][SUDOKU]);
void editSquare                                      (int board[][SUDOKU]);
char getCoordinates                                   (int &row, int &col);
void displayPossible                                 (int board[][SUDOKU]);
void writeBoard                 (char saveFileName[], int board[][SUDOKU]);
void computeValues (int possible[], int board[][SUDOKU], int row, int col);


/***********************************************************************
************************************************************************
** MAIN                                                               **
**      Will drive the program. Functions will be called from here    **
**      so that the game may be created. Board container is created.  **
***********************************************************************/
int main()
{
   // Set up the containers
   char fileName[MAX];
   int board[SUDOKU][SUDOKU];           // This is the board

   // Get the filename
   getFileName(fileName);

   // Now that we have filename
   //   Read it into the container
   readFile(board, fileName);

   // Display the options menu
   displayOptions(board);

   // Now display the board
   displayBoard(board);

   // Allow the user to interact
   interact(board);

   // Write board to file
   char saveFileName[MAX];
   writeBoard(saveFileName, board);

   return 0;
}

/**********************************************************************
* GETFILENAME                                                        **
*       Will get the file name from the user.                        **
**********************************************************************/
void getFileName(char fileName[MAX])
{
   //Prompt the user for their file 
   cout << "Where is your board located? ";
   cin  >> fileName;
   cin.ignore();                        // Clear the buffer just in case.

}

/**********************************************************************
* READFILE                                                           **
*       Will read the file and do error checking. Then it will read  **
*       the file into the board array.                               **
**********************************************************************/
void readFile(int board[][SUDOKU], char fileName[MAX])
{   
   // We got to read and check fileName!
   // Start the ifstream
   ifstream fin(fileName);

   // Is it error free?
   if (fin.fail())
   {
      cout << "Error: Unable to open "          // Oh SNAP!
           << fileName
           << endl;
   }

   // Put the file into the board
   // For Rows, read.
   for (int iRow = 0; iRow < SUDOKU; iRow++)
   {
      // For Columns, read.
      for (int iCol = 0; iCol < SUDOKU; iCol++)
         fin >> board[iRow][iCol];              // Put it into board

      if (fin.fail())
      {
         fin.close();                           // Doh! BART!!
      }
   }      
   
   // Close the file!!
   fin.close();
}

/**********************************************************************
* DISPLAYOPTIONS                                                     **
*       Displays the list of options to the user.                    **
**********************************************************************/
void displayOptions(int board[][SUDOKU])
{
   char input;
   // Prompt User and get Input
   cout << "Options:\n";      
      
   // Show the Options
   cout << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n";
      
      // Add a line
   cout << endl;
            
}

/**********************************************************************
* DISPLAYBOARD                                                       **
*       This will display the board                                  **
**********************************************************************/
void displayBoard(int board[][SUDOKU])
{
   // Display the board!
   cout << "   A B C D E F G H I\n";

   // Initialize number array
   int num[] = 
      { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

   
   // First, lets run the rows.
   for (int iRow = 0; iRow < SUDOKU; iRow++)
   {
      // Set the number and dividers up
      if (iRow == 3 || iRow == 6)
      {
         cout << "   -----+-----+-----\n"   // Adds horizontal divide
              << num[iRow]                  // Adds num array             
              << "  ";
      }
      else
      {
         // Just add the num array
         cout << num[iRow]
              << "  ";
      }                 
      // Then run through the column.
      // Find 0's and replace them.
      // Check for conditions and add
      //   the correct output.
      for (int iCol = 0; iCol < SUDOKU; iCol++)
      {
         // Add number and endline
         if (iCol % 10 == 8)
         {
            if (board[iRow][iCol] == 0)     // Replaces 0 with a space
            {
               cout << " \n";
            }
            else
            {
               cout << green << board[iRow][iCol]
                    << reset << endl;
            }
         }
         // Add number and vertical divider
         else if (iCol == 2 || iCol == 5)
         {
            if (board[iRow][iCol] == 0)     // Replaces 0 with a space  
            {
               cout << " "
                    << "|";
            }
            else
            {
               cout << green << board[iRow][iCol]
                    << reset << "|";
            }  
         }
         // Add number and space
         else
         {
            if (board[iRow][iCol] == 0)     // Replaces 0 with 2 space
            {
               cout << "  ";
            }
            else
            {
               cout << green << board[iRow][iCol]
                    << reset << " ";
            }
         }
                                     
      }
                  
   }
         
   
}

/**********************************************************************
* INTERACT                                                           **
*       Will allow the user to interact with the program. It will    **
*       prompt the user, get their input, and then perform the       **
*       selection.                                                   **
**********************************************************************/
void interact(int board[][SUDOKU])
{
   // Set up the containers
   char   input;
   
   // Set up the do while loop
   // Run through options until
   // 'Q' is pressed
   do
   {
      // Display the prompt and get user input
      cout << "\n> ";
      cin  >> input;
      input = toupper(input);

      // Set up a switch for options
      switch (toupper(input))
      {
         case '?':
            displayOptions(board);
            break;
         case 'D':
            displayBoard(board);
            break;
         case 'E':
            editSquare(board);
            break;
         case 'S':
            displayPossible(board);
            break;
         case 'Q':
            break;
         default:
            cout << "ERROR: Invalid command\n";

      }
   
   }
   // While 'Q' is not pressed
   while (input != 'Q');

}

/**********************************************************************
* EDITSQUARE                                                          *
*       This will allow the use to edit a square                      *
**********************************************************************/
void editSquare(int board[][SUDOKU])
{
   // Set up the containers
   int  row = 0;
   int  col = 0;
   char   alpha;

   // Set up the possible array
   int possible[] = 
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

   // Get coordinates from user
   alpha = getCoordinates(row, col);
   
   // Check if square if full
   // Readjust output
   if (board[row][col] != 0)
   {
      cout << "ERROR: Square '" << alpha << row + 1 << "' is filled\n";
   }
   //Prompt the user for edit
   else
   {
      cout << "What is the value at '" << alpha << row + 1 << "': ";
      int value = 0;
      cin  >> value;
      // Check that it is a possitive number
      if (value < 0)
      {
         cout << "ERROR: Value '" << value << "' in square '"
              << alpha << row + 1 << "' is invalid\n";
      }

      cin.ignore();

      // Check value against what is possible
      computeValues(possible, board, row, col); 

      // If it is not possible
      if (possible[value] == 0)
      {
         cout << "ERROR: Value '" << value << "' in square '"
              << alpha << row + 1 << "' is invalid\n";
      }
      // If it is, write it to the board.
      else
      {
         board[row][col] = value;
      }
 
   }
     
}

/**********************************************************************
* GETCOORDINATES                                                      *
*       Will prompt the user for coordinates                          *
**********************************************************************/
char getCoordinates(int &row, int &col)
{
   // Set up a char container
   char         input;
   char         tempA;                  // Temporary input container
   char         tempB;                  // Temporary input container
   bool valid = false;

   while (valid == false)
   {  
   // Prompt the user
   cout << "What are the coordinates of the square: ";
   
   cin >> tempA >> tempB;
   
      if ((isalpha(tempA) && isalpha(tempB)) || 
          (!isalpha(tempA) && !isalpha(tempB)))
      {
         cout << "ERROR: Square '" << tempA << tempB << "' is invalid\n";
         valid = false;
      }
      else
      {
         valid = true;
      }
   }

   // Check for wonky input
   if (isalpha(tempA) && isalpha(tempB))
   {
      cout << "ERROR: Square '" << tempA << tempB << "' is invalid\n";
   }
     
   // Checks for proper values and switches them
   // if wrong.
   if (!isalpha(tempA))
   {
      row = tempA - 48;                     // If a is not alpha
      input = tempB;
   }
   else if (isalpha(tempA))                 // If a is alpha
   {
      row = tempB - 48;
      input = tempA;
   }

      
    
   cin.ignore();                                        // Clear buffer
   

   // Uppercase input
   input = toupper(input);

   // Create and Alphabet Array A - I
   char alpha[] =
      { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

   // Transform char row into an int row
   for (int i = 0; i < 9; i++)
   {
      
      if (input == alpha[i])
      {
         col = i;
      }
   }
   // Adjust data
   row--;
   

   return input;
}

/**********************************************************************
* DISPLAY POSSIBLE                                                    *
*       Display's possible values                                     *
**********************************************************************/
void displayPossible(int board[][SUDOKU])
{
   // Set up Variables
   int    row;
   int    col;
   char alpha;

   // Set up possible array
   int possible[] =
      { 1, 2, 3, 4, 5, 6, 7, 8, 9};

   // Get Coordinates
   alpha = getCoordinates(row, col);

   // Compute Values
   computeValues(possible, board, row, col);

   // Put message
   cout << "The possible values for '" 
        << alpha << row + 1 
        << "' are: ";
   
   
   // Set up the loop
   bool first = true;                   // First will start off as true.
   for (int i = 0; i < 10; i++)
   {
      if (possible[i])
      {
         // If not first, comma and space
         if (!first)
         {
            cout << ", ";    //TEST
         }
                
         // Display i
         cout << i;
         
         first = false;
      }
   }
   cout << endl;
}

/**********************************************************************
* WRITEBOARD                                                         **
*       Will write the board back to a file. Yay!                    **
**********************************************************************/
void writeBoard (char saveFileName[], int board[][SUDOKU])
{
   // Prompt user for name of save file.
   cout << "What file would you like to write your board to: ";
   cin  >> saveFileName;

   // Open and declare ofstream
   ofstream fout(saveFileName);
   // Check it for errors
   if (fout.fail())                     // You lose!
   {
      cout << "Error: " << saveFileName << " failed." << endl;
   }

   // If its fine, write the file
   // First the rows
   for (int iRow = 0; iRow < SUDOKU; iRow++)
   {
      // Then the columns
      for (int iCol = 0; iCol < SUDOKU; iCol++)
      {
         fout << board[iRow][iCol] << " ";     // Put it in the bank!
      }
      
      fout << endl;
   }

   cout << "Board written successfully\n";

   // Egon: "Don't cross the streams."
   //       "Close them, or it would be bad!"
   fout.close();

}

/*************************************************************************
* COMPUTE VALUES                                                         *
*       Via the all seeing eye of Sauron, our master, we check the board *
*       for Frodo's ring (ie the number), and false or true it.          *
*            --Loops through possible[] and the board to see if they     *
*               match or not.                                            *
*              This is the brains of the search program.                 *
*************************************************************************/
void computeValues (int possible[], int board[][SUDOKU], int row, int col)
{
   // Loop through array and set it to true.
   for (int i = 0; i < 9; i++)
   {
      // Each index will be set to true
      possible[i] = true;
   }

   // Loop through the Row for the enemy numbers
   // and falsify them!
   for (int iRow = 0; iRow < 9; iRow++)
   {
      // Check the possible array against
      // The board
      possible[board[iRow][col]] = false;
   }

   // Loop through the cowardly column and falsify
   // all the numbers.
   for (int iCol = 0; iCol < 9; iCol++)
   {
      // check the possible array against
      // The board
      possible[board[row][iCol]] = false;
   }

   // Now we summon the Eye of Sauron
   // to check the 3X3 square for Frodo's ring
   // ie, the offending number.
   for (int iRow = 0; iRow < 2; iRow++)
   {
      for (int iCol = 0; iCol < 2; iCol++)
      {
         // A good ole Orcan math formula
         possible[board[row / 3 * 3 + iRow][col / 3 * 3 + iCol]] = false;
      }
   }
}