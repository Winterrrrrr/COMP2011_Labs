#include <iostream>
using namespace std;
  
int main()
{
    /*
        There are 4 errors in total. Can you catch them all? :)
  
        See the expected output section on the lab page to see what is expected from the corrected program.
    */
  
    int number;/*1*/
    cout << "Welcome to the exciting, fun, and awesome programming world! "
         << "Enter an odd number, and I can tell something about you! " << /*2*/endl;
    cin >> number;
  
    if (number % 2 ==/*3*/ 0) 
        cout << "Hmm... this is not an odd number..." << endl;
    else
    {
        if (number < 0)
            cout << "You seem to be a bit negative... :( Cheer up! " << endl;
        else
            cout << "You must be very excited! Me too! :)" << endl;
  
 
    }/*4*/

      return 0;
}