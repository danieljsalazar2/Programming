//
// infiniteLoop.cpp
//
// Keith Mehl
// 8/29/18
// CSCI-14 example program
// illustrate the dangers of an off-by-one error in a loop
// this is a SUBTLE infinite loop
//
#include <iostream>
using namespace std;

int main()
{
    int i, a[3];
    for( i = 0; i <= 3; i++ )
    {
        a[i] = 0;
        cout << "i = " << i << endl;
    }
    return 0;
}
