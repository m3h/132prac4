#include "reduce.h"
#include <string>
#include <iostream>

using namespace std;

int a, b;
bool again = true;
string answer;

int main()
{
	while(again)
	{
		cout << "Enter a: ";
		cin >> a;

		cout << "Enter b: ";
		cin >> b;

		cout << "Testing displayFraction" << endl;
		cout << "\tThe fraction entered is ";
		displayFraction(a, b);
		cout << endl;
		
		cout << "\tdisplayFraction(" << a <<") yields ";
		displayFraction(a);
		cout << endl;
		
		cout << "\tdisplayFraction() yields ";
		displayFraction();
		cout << endl;
		
		cout << "\nTesting gcd()" << endl;
		cout << "\tThe GCD of " << a << " and " << b;
		cout << " is " << gcd(a, b) << endl;

		cout << "\nTesting reduceFraction()" << endl;

		cout << '\t' << a << ", " << b << " reduce to ";
		if (reduceFraction(a, b))
		{
			cout << a << ", " << b << endl;
		}
		else
		{
			cout << "Error reducing" << endl;
		}
		cout << "Run again? (Y/N): ";
		cin >> answer;
		again = toupper(answer[0]) == 'Y';
	}
}