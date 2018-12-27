//
// arrayStruct.cpp
//
// Keith Mehl 11/30/04
// CSCI-14 example program
// Illustrate using an array of structs
// data file for this is students.txt
//
#include <iostream>
#include <fstream>
using namespace std;
#define SUCCESS 0
#define FAILURE (!(SUCCESS))
#define MAX 100
struct STUDENT
{
    char wNum[10];    // W-number - 9 chars + 1 for NUL (KEY)
    char fName[MAX];  // first name - program assumes no spaces in names
    char lName[MAX];  // last name
    int age;
    float gpa;
};

// read one STUDENT from input stream by reference
// return success (0) if read, failure (non-0) if end-of-file
// the istream & parameter allows this to be called using either an
// istream (cin) or an ifstream  (polymorphic)
int ReadPerson( istream &in, STUDENT &p )
{
    if( in >> p.wNum >> p.fName >> p.lName >> p.age >> p.gpa )
    {
        return SUCCESS;
    }
    return FAILURE;
}
// Print STUDENT to ostream out
void PrintPerson( ostream &out, STUDENT &p )
{
    out << "W-number  : " << p.wNum << "\nFirst Name: " << p.fName
        << "\nLast Name : " << p.lName << "\nAge       : " << p.age
        << "\nGPA       : " << p.gpa << endl;
    return;
}

int main( void )
{
    ifstream fin( "students.txt" );
    STUDENT people[MAX];
    int ct = 0, i;
    if( !fin )
    {
        cout << "Error opening file!\n" << flush;
        return -1;
    }
    // read the people into the array
    while( ct < MAX && ReadPerson( fin, people[ct] ) == SUCCESS )
    {
        ct++;
    }
    cout << "We read " << ct << " people" << endl;
    // print them back out
    for( i = 0; i < ct; i++ )
    {
        PrintPerson( cout, people[i] );
        cout << "-------------------------------" << endl;
    }
    // find the middle person and print the GPA
    // what is the error in the following code?
    i = ct / 2;
    cout << "For the middle person (at position " << i << "), "
         << people[i].fName << ", the GPA is "
         << people[i].gpa << endl;
    // code for error question stops here
    fin.close();
    return 0;
}

