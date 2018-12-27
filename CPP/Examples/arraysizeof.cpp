//
// arraysizeof.cpp
//
// Keith Mehl
// 7/26/17
// CS14/15 example program
// show sizeof() array in scope and as a parameter
//

#include <iostream>
using namespace std;

void foo( int [] );

int main()
{
    int arr[10];
    cout << "In main(), sizeof(arr) is " << sizeof(arr) << endl;
    foo( arr );
    return 0;
}

void foo( int a[] )
{
    cout << "In foo(), sizeof(a) is " << sizeof(a) << endl;
    return;
}
