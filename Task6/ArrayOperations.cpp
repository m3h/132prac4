// function definitions of ArrayOperations.h


double getTotal( const double array[ROW][COL] )
{
    double total = 0;

    for( int i = 0; i < ROW; i++ )
        for( int j = 0; j < COL; j++ )
            total += array[i][j];

    return total;
}

double getTotal( int rowNo, const double array[ROW][COL] );
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
        total += array[i][COL];

    return total;
}
