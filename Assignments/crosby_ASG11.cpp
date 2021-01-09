/***********************************************************************
* Program:
*    Assignment 11, Monthly Budget
*    Brother Foushee, CS124
* Author:
*    Estimated:  1.5 hrs   
*    Actual:     2.0 hrs
* The most difficult part was learning the newer commands and lining up the columns
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * The main() function contains the primary function for the whole program
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios:: showpoint);
   cout.precision(2);
   cout << "\tItem           Projected" << endl;
   cout << "\t=============  ==========" << endl;
   cout << "\tIncome         $" << setw(9) << "1000.00" << endl;
   cout << "\tTaxes          $" << setw(9) << "100.00" << endl;
   cout << "\tTithing        $" << setw(9) << "100.00" << endl;
   cout << "\tLiving         $" << setw(9) << "650.00" << endl;
   cout << "\tOther          $" << setw(9) << "90.00" << endl;
   cout << "\t=============  ==========" << endl;
   cout << "\tDelta          $" << setw(9) << "60.00" << endl;
   return 0;
}