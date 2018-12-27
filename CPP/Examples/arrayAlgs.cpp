//
// arrayAlgs.cpp
//
// Keith Mehl
// 11/16/09
// CSCI-14 example program
// Illustrate insertion and deletion algorithms on arrays holding sorted lists
//

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;  // 100 array elements

// print first ct elements of array a with reasonable width, assuming
// numbers are less than 4 digits and array data will fit on one line...
void PrintIt( int a[], int ct )
{
   for( int i = 0; i < ct; i++ )
   {
      cout << setw(4) << a[i];
   }
   cout << endl;
   return;
}

int main()
{
   int a[MAX] = { 0 }, ct = 0, n, i, j;
   // first, build an ordered list of elements
   cout << "Enter elements to insert into array, <= 0 to stop : " << flush;
   cin  >> n;
   // until we either run out of room or get a stop sentinel
   while( ct < MAX && n > 0 )
   {
      // insert n into array a in sorted order
      // this insertion algorithm is not quite the fastest possible.  why?
      i = 0;  // scan from left looking for place to insert
      // we can either run off the end of the list or find a spot inside list
      // why do I check i < count first here, not a[i] < n first?
      while( i < ct && a[i] < n )
      {
         i++;
      }
      // if at the end, just add to end of table
      if( i >= ct )
      {
         a[ct++] = n;
      }
      else  // otherwise, shift over everything to the right to make a hole
      {
         for( j = ct; j > i; j-- )
         {
            a[j] = a[j-1];
         }
         a[j] = n;
         ct++;
      }
      PrintIt( a, ct );
      if( ct < MAX )  // only read next number if there is room
      {
         cin >> n;
      }
   }
   // now to remove elements by key, if duplicate key remove first one in list
   cout << "Enter elements to remove from array, <= 0 to stop : " << flush;
   cin  >> n;
   // we can run out of elements in the array or get the stop sentinel
   while( ct > 0 && n > 0 )
   {
      // find element in the array
      // stopping if we go past it (since array is sorted)
      // this is logically equivalent to while loop above, scanning for n
      for( i = 0; i < ct && a[i] < n; i++ ); // note the empty loop body!

      if( i < ct && a[i] == n ) // found it?
      {
         for( j = i; j < ct; j++ )
         {
            a[j] = a[j+1];
         }
         ct--;
      }
      else
      {
         cout << n << " is not in the list." << endl;
      }
      PrintIt( a, ct );
      if( ct > 0 )  // don't bother getting another key if the list is empty
      {
         cin >> n;
      }
   }
   return 0;
}
