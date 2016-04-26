#include <iostream>
#include "ChipsAndSalsa.h"
#include <iomanip>

using namespace std;

int getInput();
void displayReport();
int getTotal();
int getMaxSalsa();
int getMinSalsa();
 
int main()
{
    int errorCount;
    errorCount = getInput();

    displayReport();

    cout << "Warning: A total of " << errorCount << " errors were encountered during input." << endl;

    return 0;
}

int getInput()
{
    int errorCount = 0;
    double input;

    for( int i = 0; i < NUM_OF_SALSA_TYPES; i++ )
    {
        cout << "Enter the number of jars of " << salsaName[i] << " sold: ";
        cin >> input;

        if( input < 0.0 )
        {
            input = 0.0;
            ++errorCount;
        } else if( (input - static_cast<int>(input)) != 0.0 )
            ++errorCount;

        numOfJars[i] = static_cast<int>(input);
    }

    return errorCount;
}

void displayReport()
{
    cout << "**************************" << endl;
    cout << "* CHIPS AND SALSA REPORT *" << endl;
    cout << "**************************" << endl;

    cout << left << setw(8) << "Name:" << right << setw(15) << "Amount:" << endl;

    for( int i = 0; i < NUM_OF_SALSA_TYPES; i++ )
    {
        cout << left << setw(8) << salsaName[i] << right << setw(13) << numOfJars[i] << endl;
    }

    cout << "----------------------" << endl;
    cout << left << setw(8) << "Total:" << right << setw(13) << getTotal() << endl;
    cout << "----------------------" << endl;

    int maxSalsa, minSalsa;
    maxSalsa = getMaxSalsa();
    minSalsa = getMinSalsa();

    cout << "The maximum sold was " << salsaName[maxSalsa] << " at " << numOfJars[maxSalsa] << " jars." << endl;

    cout << "The minimum sold was " << salsaName[minSalsa] << " at " << numOfJars[minSalsa] << " jars." << endl;

}

int getTotal()
{
    int total = 0;
    for( int i = 0; i < NUM_OF_SALSA_TYPES; i++ )
        total += numOfJars[i];

    return total;
}
int getMaxSalsa()
{
    int maxVal = 0, maxIndex = 0;

    for( int i = NUM_OF_SALSA_TYPES - 1; i >= 0; i-- )
    {
        if( numOfJars[i] > maxVal )
        {
            maxVal = numOfJars[i];
            maxIndex = i;
        }
    }
    
    return maxIndex;
}


int getMinSalsa()
{
    int minVal, minIndex = 0;
    minVal = numOfJars[getMaxSalsa()];   // set the inital min to the highest possible;

    for( int i = 0; i < NUM_OF_SALSA_TYPES; i++ )
    {
        if( numOfJars[i] < minVal )
        {
            minVal = numOfJars[i];
            minIndex = i;
        }
    }
    
    return minIndex;
}
