#include <iostream>
#include <cmath>

#include "reduce.h"

using namespace std;

int main()
{
    cout << "Fraction Reduction" << endl;
    cout << "-------------------------------" << endl;

    int a, b;

    cout << "Enter the numerator: ";
    cin >> a;

    cout << "Enter the denominator: ";
    cin >> b;

    int absA, absB; // Get absolute values of variables
    absA = abs(a);
    absB = abs(b);

    if( b == 0 )
    {
        cout << "Error! division by zero" << endl;
        cout << "Terminating..." << endl;
        return 0;
    }

    cout << "The GCD of " << absA << " and " << absB << " is " << gcd( absA, absB ) << endl;

    cout << "The lowest form of ";
    displayFraction( a, b );
    cout << " is ";

    if( ( a * b ) < 0 ) // it's positive
        cout << "-";

    reduceFraction( absA, absB );
    displayFraction( absA, absB );

    cout << " = " << static_cast<double>(a)/b << endl;

    return 0;
}

