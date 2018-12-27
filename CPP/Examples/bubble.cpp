//
// bubble.cpp
// Keith Mehl 10/26/2005
// CSCI-14 Example program
// Illustrate bubble sort algorithm
//

#include <iostream>
using namespace std;

void exchange( int &a, int &b )
{
    int t = a;
    a = b;
    b = t;
    return;
}

void PrintIt( int a[], int n )
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

void BubbleSort( int a[], int n )
{
    int i;
    bool sorted = false;
    while( !sorted )
    {
        sorted = true;
        for( i = 0; i < n-1; i++ )
        {
            if( a[i] > a[i+1] )
            {
                sorted = false;
                exchange( a[i], a[i+1] );
            }
        }
        PrintIt( a, 6 );
    }
    return;
}

int main()
{
    int i, a[6] = { 6, 5, 4, 3, 2, 1 };
    PrintIt( a, 6 );
    BubbleSort( a, 6 );
    return 0;
}

