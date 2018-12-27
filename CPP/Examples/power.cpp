//
// power.cpp
//
// Keith Mehl
// 10/11/07
// CSCI-14 example program - implement a simple Power() function
// and illustrate the conditional or ternary operator ?:
//
#include <iostream>
using namespace std;

// calculate and return x to the p power
// assume 0 to the 0 is 1
double Power( double x, int p ) // function definition
{
   double t = 1.0;
   int i, stopat = p >= 0 ? p : -p; // p negative? count up not down
   // By starting with t == 1.0, you don't need a separate test for
   // 'is the power p 0' before the loop.  Instead of multiplying x by
   // itself for a total of p factors, multiply 1.0 by x p times
   for( i = 0; i < stopat; i++ )
   {
      t *= x;
   }
   // negative power? return reciprocal
   return p >= 0 ? t : 1.0 / t;
}

int main()
{
   double x, y;
   int p;
   char more;

   do
   {
      cout << "Enter x : " << flush;
      cin  >> x;
      cout << "Enter p : " << flush;
      cin  >> p;
      y = Power( x, p );
      cout << x << " to the " << p << " power is " << y << endl;
      cout << "\nAnother? " << flush;
      cin  >> more;
   } while( more == 'Y' || more == 'y' );
   return 0;
}

