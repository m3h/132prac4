#include <iostream>
#include <fstream>
#include <string>

#include "ArrayOperations.h"

using namespace std;

int populate( double array[ROW][COL] );

int main()
{
    double array[ROW][COL] = {}; 
    cout << populate( array );
        return 0;
}

int populate( double array[ROW][COL] )
{
    string filename;
    cout << "Please enter file name: ";
    cin >> filename;

    ifstream inputFile;
    inputFile.open( filename.c_str() );

    if( !inputFile )
    {
        cout << "Error opening file " << filename << endl;
        cout << "Terminating..." << endl;
        return -1;
    }

    int noVals = 0;
    double val;
    bool endReached = false;

    for( int i = 0; i < ROW && !endReached; i++ )
        for( int j = 0; j < COL; j++ )
        {
            if( inputFile >> val )
            {
                array[i][j] = val;
                noVals++;
            } else
            {
                endReached = true;
                break;
            }
        }

    if( noVals != ROW * COL )
    {
        cout << "This program needs " << ROW * COL << " real values to fill an array with " << ROW << " and " << COL << " columns." << endl;
        cout << "Only " << noVals << " real values could be read from the file called " << filename << "." << endl;

        return noVals;
    }

    return 0;
}

