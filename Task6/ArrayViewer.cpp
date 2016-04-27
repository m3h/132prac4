#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "ArrayOperations.h"

using namespace std;

#define FORMAT right << setw(WIDTH) << fixed << setprecision(2)

int populate( double array[ROW][COL] );

void printLine();

void printArray( const double array[ROW][COL] );
void printHeader();
void printMiddle( const double array[ROW][COL] );
void printFooter( const double array[ROW][COL] );

int main()
{
    double array[ROW][COL] = {}; 
    if( populate( array ) )
        return 0;

    printArray( array );
    
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

        return -2;
    }

    return 0;
}

void printArray( const double array[ROW][COL] )
{
    printHeader();
    printMiddle( array );
    printFooter( array );
}

void printHeader()
{
    for( int i = 0; i < COL; i++ )
        for( int j = 0 ; j < WIDTH; j++ )
            cout << " ";

    cout << " |";

    cout << right << setw(WIDTH) << "Total";
    cout << right << setw(WIDTH) << "Max";
    cout << right << setw(WIDTH) << "Min";
    cout << endl;

    printLine();
}


void printMiddle( const double array[ROW][COL] )
{
    for( int i = 0; i < ROW; i++ )
    {
        for( int j = 0; j < COL; j++ )
            cout << right << setw(WIDTH) << fixed << setprecision(2)
                << array[i][j];
        cout << " |";


        cout << right << setw(WIDTH) << fixed << setprecision(2)
            << getTotal( i + 1, array );
        cout << right << setw(WIDTH) << fixed << setprecision(2)
            << getHighest( i + 1, array );
        cout << right << setw(WIDTH) << fixed << setprecision(2)
            << getLowest( i + 1, array );
        cout << endl;
    }

}

void printFooter( const double array[ROW][COL] )
{
    printLine();

    for( int i = 0; i < COL; i++ )
    {
        cout << right << setw(WIDTH) << fixed << setprecision(2)
            << getTotal( array, i + 1 );
    }
    cout << " |";

    double total = 0;
    for( int i = 0; i < ROW; i++ )
        total += getTotal( i + 1, array );

    cout << right << setw(WIDTH) << fixed << setprecision(2)
        << total;

    double max = getHighest( 1, array );
    for( int i = 1; i <= ROW; i++ )
        if( max < getHighest( i, array ))
                max = getHighest( i, array );
    
    cout << right << setw(WIDTH) << fixed << setprecision(2)
    << max;

    double min = getLowest( 1, array );

    for( int i = 1; i <= ROW; i++ )
        if( min > getLowest( i, array ) )
            min = getLowest( i, array );
    cout << right << setw(WIDTH) << fixed << setprecision(2)
        << min;
    cout << endl;
}

void printLine()
{

    for( int i = 0; i < COL; i++ )
        for( int j = 0; j < WIDTH; j++ )
            cout << "-";

    cout << "-|";

    for( int i = 0; i < 3; i++ )
        for( int j = 0; j < WIDTH; j++ )
            cout << "-";
    cout << endl;
}
