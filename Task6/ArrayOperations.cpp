// function definitions of ArrayOperations.h
#include "ArrayOperations.h"

double getTotal( const double array[ROW][COL] )
{
    double total = 0;

    for( int i = 0; i < ROW; i++ )
        for( int j = 0; j < COL; j++ )
            total += array[i][j];

    return total;
}

double getTotal( int rowNo, const double array[ROW][COL] )
{
    double total = 0;

    for( int i = 0; i < COL; i++ )
        total += array[rowNo][i];

    return total;
}

double getTotal( const double array[ROW][COL], int colNo )
{
    double total = 0;

    for( int i = 0; i < ROW; i++ )
        total += array[i][colNo];

    return total;
}


double getAverage( const double array[ROW][COL] )
{
    return getTotal( array ) / ( ROW * COL );
}

double getAverage( int rowNo, const double array[ROW][COL] )
{
    return getTotal( rowNo, array ) / COL;
}

double getAverage( const double array[ROW][COL], int colNo )
{
    return getTotal( array, colNo ) / ROW;
}

double getHighest( const double array[ROW][COL] )
{
    double highest = array[0][0];

    for( int i = 0; i < ROW; i++ )
        for( int j = 0; j < COL; j++ )
            if( array[i][j] > highest )
                highest = array[i][j];

    return highest;
}

double getHighest( int rowNo, const double array[ROW][COL] )
{
    double highest = array[rowNo][0];

    for( int i = 0; i < COL; i++ )
        if( array[rowNo][i] > highest )
            highest = array[rowNo][i];

    return highest;
}

double getHighest( const double array[ROW][COL], int colNo )
{
    double highest = array[0][colNo];

    for( int i = 0; i < ROW; i++ )
        if( array[i][colNo] > highest )
            highest = array[i][colNo];

    return highest;
}


double getLowest( const double array[ROW][COL] )
{
    double lowest = array[0][0];

    for( int i = 0; i < ROW; i++ )
        for( int j = 0; j < COL; j++ )
            if( array[i][j] < lowest )
                lowest = array[i][j];

    return lowest;
}

double getLowest( int rowNo, const double array[ROW][COL] )
{
    double lowest = array[rowNo][0];

    for( int i = 0; i < COL; i++ )
        if( array[rowNo][i] < lowest )
            lowest = array[rowNo][i];

    return lowest;
}

double getLowest( const double array[ROW][COL], int colNo )
{
    double lowest = array[0][colNo];

    for( int i = 0; i < ROW; i++ )
        if( array[i][colNo] < lowest )
            lowest = array[i][colNo];

    return lowest;
}
