//
// primes.cpp
//
// Keith Mehl
// Oct. 16, 2000
// CSCI-14 example program
// Illustrate Boolean value-returning function IsPrime()
// The function IsPrime() takes an integer and returns true
// if it is prime, else false.
// This program uses IsPrime() to list all prime numbers from 1 to 1000
//
#include <iostream>
#include <cmath>
using namespace std;
const int MaxVal = 1000;  // stop searching for prime numbers at 1000 max
const int PerLine = 8;    // 8 numbers per line for fence-post solution
bool IsPrime( int ); // function prototype (declaration)
// or you can place the function definition above main()

int main()
{
    // count 1 from 1 to MaxVal, if i is prime, print it
    int ct = 0;  // to count the number of primes printed on a single line
    int i;
    for( i = 1; i <= MaxVal; i++ )
    {
        if( IsPrime( i ) ) // IsPrime() return value is if() test value
        {
            cout << i;
            if( ++ct == PerLine )  // a solution to the "fence post" problem
            {
                ct = 0;
                cout << endl;
            }
            else
            {
                cout << '\t' << flush;
            }
        }
    }
    if( ct != 0 )  // terminate last line only if needed
    {
        cout << endl;
    }
    return 0;
}

// IsPrime() returns TRUE if its parameter n is prime, else FALSE
bool IsPrime( int n )   // function definition
{
    int lastDiv; // where to stop, sqrt(n) is be maximum factor we need to test
    bool prime = true; // assume n is prime until otherwise proven
    int i;       // loop counter
    if( n <= 2 ) // negative or 0 or 1 isn't prime; 2 is prime
    {
        prime = (n == 2); // <= 1 false, 2 (max possible after if test) true
    }
    if( n > 2 && !( n % 2 ) )  // divisible by 2 == not prime
    {
        prime = false;
    }
    // otherwise loop from 3 through square root of number counting by 2
    lastDiv = static_cast<int>( sqrt( static_cast<double>( n ) ) );
    i = 3;
    while( prime && i <= lastDiv )
    {
        if( !( n % i ) )  // if any odd value divides number, not prime
        {
            prime = false;
        }
        i += 2;
    }
    return prime;  // if nothing divides number evenly, it's prime
}


