#ifndef ARRAY_OPERATIONS
#define ARRAY_OPERATIONS 

const int ROW = 7;
const int COL = 5;
const int WIDTH = 10;

/* Returns the sum of all the values in the array passed as parameter*/
double getTotal(const double[ROW][COL]);


/* The first argument is the subscript of a row in the array passed as the second parameter
The function returns the sum of the values in the specified row.*/
double getTotal(int, const double[ROW][COL]);


/* The second argument is the subscript of a column in the array passed as the first parameter
The function returns the sum of the values in the specified column.*/
double getTotal(const double[ROW][COL], int);


/* Returns the average of all the values in the array passed as parameter*/
double getAverage(const double[ROW][COL]);


/* Returns the highest of all the values in the array passed as parameter*/
double getHighest(const double[ROW][COL]);


/* Returns the lowest of all the values in the array passed as parameter*/
double getLowest(const double[ROW][COL]);

#endif