//
// kilos.cpp
//
// Keith Mehl
// Sept. 12, 2000
//
// CSCI-14 example program
// Convert a weight given in kilograms to integer pounds
// and ounces with fraction displayed rounded to 2 decimal places
//

#include <iostream>
#include <iomanip> // header allows output manipulation (formatted output)
using namespace std;

const float LbPerKilo = (float)2.204623; // skip truncation warning with cast
const float OzPerLb   = (float)16.0;     // C-type casts, C++ type is below

int main()
{
    float kilos, totalPounds, ounces;
    int pounds;

    cout << "Enter weight in kilograms: " << flush;
    cin  >> kilos;

    totalPounds = kilos * LbPerKilo;
            // explicitly cast totalPounds to int type with C++ static cast
    pounds = static_cast<int>(totalPounds);
    ounces = OzPerLb * (totalPounds - pounds); // fraction of lb to ounces
            // echo-print user's input (usually not needed)
    cout << "You entered " << kilos << " kilograms." << endl;
            // showpoint means always show decimal point.
            // fixed means always leave in decimal notation,
            // i.e., don't let output go to scientific notation.
            // With both of these, setprecision() means rounded places
            // after the decimal point, otherwise setprecision()
            // refers to total number of places of precision
            // (pre- and post-decimal point combined).
    cout << showpoint << fixed
         << "That converts to " << pounds << " pounds and "
         << setprecision(2) << ounces << " ounces." << endl;
    return 0;
}

