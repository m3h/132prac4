#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{   // Get data!
    ifstream dataIn;

    dataIn.open("raindata.txt"); // open the file with all the recorded rain readings

    if(!dataIn)
    {
        cout << "Error opening file \"raindata.txt\"! Terminating now." << endl; // If opening fails, terminate
        return 0;
    }

    int rainData[364] = {};
    for( int i = 0; i < 364; i++ ) // transfer data from file to array
    {
        dataIn >> rainData[i];
    }


    
    // Get user input!
    int weekIndex = 1, noWeeks = 1;

    cout << "Enter the starting week's index [1 - 52]: ";
    cin >> weekIndex;

    if ( weekIndex < 1 || weekIndex > 52 )
    {
        cout << "You entered " << weekIndex << " where only values [1 - 52] are valid." << endl;
        return 0;
    }

    int noWeeksMax = 52 - weekIndex + 1; // caluclate max number of weeks able to be displayed
    cout << "Enter the number of weeks [1 - " << noWeeksMax << "]: ";
    cin >> noWeeks;

    if ( noWeeks < 1 || noWeeks > noWeeksMax )
    {
        cout << "You entered " << noWeeks << " where only values [1 - " << noWeeksMax << "] are valid." << endl;
        return 0;
    }


    // Display Graph!
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << setw(34) << right << " " << "Relative Weekly Rainfall (%)" << endl;
    cout << " ";
    for( int i = 0; i <= 100; i += 5 )

    {
        cout << setw(4) << i;
    }
    cout << endl; 

    cout << "    ";
    for( int i = 0; i <= 80; i++ )
    {
        if ( i % 4 )
            cout << "-";
        else
            cout << "+";
    }
    cout << endl;

    // total the rainfall for the period
    int totalRain = 0;
    for( int i = (weekIndex - 1) * 7; i < (weekIndex - 1) * 7 + noWeeks * 7; i++ )
    {
        totalRain += rainData[i];
    }

    for( int i = weekIndex; i < weekIndex + noWeeks; i++ )
    {
        cout << setw(4) << right << i << "|";

        // total the rain measured for the week
        int weeklyRain = 0;
        for( int j = (i - 1) * 7; j < (i - 1) * 7 + 7; j++ )
        {
            weeklyRain += rainData[j];
        }

        int noSigns = 0;
        // Calculate number of '=' needed for display, as a fraction of 80
        noSigns = nearbyint( (static_cast<double>(weeklyRain) / totalRain) * 80 );

        for ( int j = 0; j < noSigns; j++ )
        {
             cout << "=";
        }

        cout << endl;
    }

    cout << "--------------------------------------------------------------------------------------" << endl;

    return 0;
}
