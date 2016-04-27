#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define hoursArrayMAX 10000

int getHours( double hoursArray[], int hoursMAX );
int displayHours( double hoursArray[], int hoursMAX );
double avgHours( double hoursArray[], int hoursMAX );

int main()
{
    double hoursArray[hoursArrayMAX];

    cout << "Enter 999 to stop input" << endl;

    if (getHours( hoursArray, hoursArrayMAX ) != 0)
    {

        cout << "----------------------------------------------------------" << endl;
        cout << "The hours you entered are: ";
        displayHours( hoursArray, hoursArrayMAX );
        cout << endl;

        cout << "The employee(s) worked an average of " << avgHours( hoursArray, hoursArrayMAX ) << " hours this week." << endl;
        cout << "----------------------------------------------------------" << endl;
        return 0;
    }

    return -1;
}

int getHours( double hoursArray[], int hoursMAX )
{
    int i = 0;
    do
    {
        double hours;

        cout << "Enter the hours worked by employee #" << i+1 << ": ";

        string input;
        getline( cin, input );

        hours = atof( input.c_str() );

        if ( hours == 999 )
        {
            hoursArray[i] = hours;
            return 1;
        } else if ( hours < 0 || hours > 50 )
        {
            cout << "----------------------------------------------------------" << endl;
            cout << "You have entered " << hours << ". It is invalid. Program terminated." << endl;
            cout << "----------------------------------------------------------" << endl;
            return 0;
        } else if ( hours == 0 || hours > 40 )
        {
            cout << "You have entered " << hours << ", which is an abnormal input. Please confirm input (Y or N): ";
            getline( cin, input );

            if ( input == "N" || input == "n" )
            {
                cout << "----------------------------------------------------------" << endl;
                cout << "You have entered " << hours << " and indicated that it is invalid. Program terminated." << endl;
                cout << "----------------------------------------------------------" << endl;
                return 0;
            } else if ( input == "Y" || input == "y" )
            {
            } else
            {
                cout << "Fuck knowns" << endl;
                return 0;
            }
        } else if ( hours == 999 )
        {
            hoursArray[i] = hours;
            return 1;
        }

        hoursArray[i++] = hours;
    } while ( i < hoursMAX );

   cout << "Array out of memory" << endl;
   return 0;
}

int displayHours( double hoursArrays[], int hoursMAX )
{
    for( int i = 0; i < hoursMAX && hoursArrays[i] != 999; i++ )
    {
        cout << hoursArrays[i] << " ";
    }
}

double avgHours( double hoursArrays[], int hoursMAX )
{
    double total = 0;
    int i;
    for( i = 0; i < hoursMAX && hoursArrays[i] != 999; i++ )
    {
        total += hoursArrays[i];
    }

    return total / i;
}
