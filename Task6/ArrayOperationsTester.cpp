#include <iostream>

#include "ArrayOperations.h"    // functions to be tested
using namespace std;

int main()
{
    double array[ROW][COL] = {};

    int count = 1; // initialize and display array, counting from 1 up
    for( int i = 0; i < ROW; i++ )
    {
        for( int j = 0; j < COL; j++ )
        {
            array[i][j] = count++;
            cout << " ";
        }
        cout << endl;
    }

    cout << "getTotal, then of row 1, then column 3:" << endl;
    cout << getTotal( array ) << endl;
    cout << getTotal( 1, array ) << endl;
    cout << getTotal( array, 3 ) << endl;
    cout << endl;

    cout << "getAverage, then row 3, then column 5:" << endl;
    cout << getAverage( array ) << endl;
    cout << getAverage( 3, array ) << endl;
    cout << getAverage( array, 5 ) << endl;
    cout << endl;

    cout << "getHighest, then row 4, then column 4:" << endl;
    cout << getHighest( array ) << endl;
    cout << getHighest( 4, array ) << endl;
    cout << getHighest( array, 4 ) << endl;
    cout << endl;

    cout << "getLowest, then row 4, then column 4:" << endl;
    cout << getLowest( array ) << endl;
    cout << getLowest( 4, array ) << endl;
    cout << getLowest( array, 4 ) << endl;
    cout << endl;

    return 0;
}
