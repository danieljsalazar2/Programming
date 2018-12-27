//
// ripple.cpp
// Keith Mehl
// 11/2/05
//
// CSCI-14 Example Program
// Illustrate ripple sort
//

#include <iostream>
using std::cout; // you can specify individual labels in using statements
using std::flush;
using std::endl;

void exchange( int &a, int &b )
{
    int t = a;
    a = b;
    b = t;
    return;
}

void printIt( int a[], int n )
{
    for( int i = 0; i < n; i++ )
    {
        cout << a[i];
        if( i == n-1 )
        {
            cout << endl;
        }
        else
        {
            cout << ' ' << flush;
        }
    }
    return;
}

void RippleSort( int a[], int n )
{
    int i, j;
    for( i = 0; i < n-1; i++ )
    {
        for( j = i+1; j < n; j++ )
        {
            if( a[i] > a[j] )
            {
                exchange( a[i], a[j] );
            }
        }
        printIt( a, 6 );
    }
    return;
}

int main()
{
    int a[6] = { 4, 2, 6, 3, 1, 5 };
    printIt( a, 6 );
    RippleSort( a, 6 );
    return 0;
}

