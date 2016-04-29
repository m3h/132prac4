#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define hoursArrayMAX 1000

void printLine();
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

    return 0;
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

        if( hours == 999 )
        {
            hoursArray[i++] = static_cast<int>(hours);
            return 1;
        }

        if( hours > 50 || hours < 0 )
        {
            printLine();
            cout << "You have entered " << static_cast<int>(hours) << ". It is invalid. Program terminated." << endl;
            printLine();
            exit(0);
        }

        if( hours > 40 || hours == 0 )
        {
            cout << "You have entered " << static_cast<int>(hours) << ", which is an abnormal input. Please confirm input (Y or N): ";
            getline( cin, input );

            if( input == "N" || input == "n" )
            {
                printLine();
                cout << "You have entered " << static_cast<int>(hours) << " and indicated that it is invalid. Program terminated." << endl;
                printLine();
                exit(0);
            }
        }

        hoursArray[i++] = static_cast<int>(hours);

     } while( i < hoursMAX && hoursArray[i] != 999 ); 

   cout << "Array out of memory" << endl;
   exit(0);
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

void printLine()
{
    cout << "----------------------------------------------------------" << endl;
}
