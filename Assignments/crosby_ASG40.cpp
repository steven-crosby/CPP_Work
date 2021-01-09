/*************************************************************************
* Program:
*    Assignment 40, Multi Dimensional Arrays
*    Brother Foushee, CS124
* Author:
*    Steven Crosby
* Summary: 
*    Write a function to read a Tic-Tac-Toe board into an array.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
*************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

const int TIC = 3;

void getFile(char filename[])
{
   cout << "Enter source filename: ";
   cin >> filename;
}

void display(char tictoe[][TIC])
{
   for (int j = 0; j <=2 ; j++)
   {
      for (int i = 0; i <= 2; i++)
      {
         if (tictoe[j][i] == '.')
            tictoe[j][i] = ' ';  
      }
   }
   cout << " " << tictoe[0][0] << " "
      << "| " << tictoe[0][1] << " "
      << "| " << tictoe[0][2] << " \n"; 
   cout << "---+---+---\n";
   cout << " " << tictoe[1][0] << " "
      << "| " << tictoe[1][1] << " "
      << "| " << tictoe[1][2] << " \n"; 
   cout << "---+---+---\n"; 
   cout << " " << tictoe[2][0] << " "
      << "| " << tictoe[2][1] << " "
      << "| " << tictoe[2][2] << " \n";
}

void readFile(char file[], char tictoe[][TIC])
{
   getFile(file);
   ifstream fin(file);

   if (fin.fail())
   {
      cout << "Error reading the file.";
      return;
   }
   
   for (int j = 0; j <=2 ; j++)
   {
      for (int i = 0; i <= 2; i++)
      {
         fin >> tictoe[j][i]; 
      }
   }
   fin.close();
}

void writeFile(char Dfile[], char tictoe[][TIC])
{
   cout << "Enter destination filename: ";
   cin >> Dfile;
   ofstream fout; 
   fout.open(Dfile); 

   for (int j = 0; j <=2 ; j++)
   {
      for (int i = 0; i <= 2; i++)
      {
         if (tictoe[j][i] == ' ')
         {
            tictoe[j][i] = '.';  
         }   
         fout << tictoe[j][i]; 
      }
   }
   cout << "File written\n";
   fout.close(); 
}

int main()
{
   char tictoe [TIC][TIC];
   char filename [256]; 
   char newfile [256]; 
   readFile(filename, tictoe);
   display(tictoe); 
   writeFile(newfile,tictoe);
   return 0;
}
