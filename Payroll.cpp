#include <iostream>

using namespace std;

#define hoursListMAX 10000
#define getHoursEND -1
#define getHoursINTERRUPT -2
#define getHoursMAXED -3

int getHours( double hoursList[], int MAX, int sentinel );
int displayHours( double hoursList[], int MAX );
double avgHours( double hoursList[], int MAX );

int main()
{
    int sentinel = 999;
    cout << "Enter 999 to stop input" << endl;

    double hoursList[hoursListMAX] = {};
    double hours;
    int getHoursState = 0;

    while( getHoursState = getHours( hoursList, hoursListMAX, sentinel ) ) 
        ;

    if ( getHoursState == getHoursEND )
    {
        cout << "The hours you entered are: " ;
        displayHours( hoursList, hoursListMAX );
        cout << "The employee(s) worked an average of "<< avgHours( hoursList, hoursListMAX ) <<" this week." << endl;

        return 0;
    } else if ( getHoursState == getHoursINTERRUPT )
    {
        return -1;
    } else if ( getHoursState == getHoursMAXED )
    {
        return -1;
            }
    {
        cout << "Unknown error!" << endl;
        return -1;
    }

}


int getHours( double hoursList[], int MAX, int sentinel )
{
    double hours;
    
    cout << "Enter the hours worked by employee #1: ";
    cin >> hours;
    int i = 0;
    for( i = 0; ( i < MAX ) && static_cast<int>( hoursList[i] = hours ) != sentinel; i++ )
    {
        if ( hours < 0 || hours > 50 )
        {
            cout << "----------------------------------------------------------" << endl;
            cout << "You have entered " << hours << ". It is invalid. Program terminated." << endl;
            cout << "----------------------------------------------------------" << endl;
            return getHoursINTERRUPT;
        } else if ( hours == 0 || hours > 40 )
        {
            cout << "You have entered " << hours << ", which is an abnormal input. Please confirm (Y or N): ";
            char answer;
            cin >> answer;

            if (answer == 'Y')
                ;
            else if (answer == 'N')
            {
                cout << "----------------------------------------------------------" << endl;
                cout << "You have entered " << hours << " and indicated that it is invalid. Program terminated." << endl;
                cout << "----------------------------------------------------------" << endl;

                return getHoursINTERRUPT;
            } else
            {
                cout << "FUcking y/n" << endl;
            }

            cout << "Enter the hours worked by employee #" << i+2 << ": ";
        }
        cin >> hours;
    }

    hoursList[i] = -666;

    if ( i >= MAX )
        return getHoursMAXED;
    else if ( static_cast<int>(hours) == sentinel )
        return getHoursEND;
    else
    {
        return -999;
    }
}

int displayHours( double hoursList[], int MAX )
{
    for( int i = 0; i < MAX && hoursList[i] != -666; i++)
    {
       cout << hoursList[i] << " ";
    }

    cout << endl;

    return 0; 
}

double avgHours( double hoursList[], int MAX )
{
    double total = 0;
    int i = 0;

    for( i = 0; i < MAX && hoursList[i] != -666; i++ )
    {
        total += hoursList[i];
    }

    return total / ( i + 1 );
}
