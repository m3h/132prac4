void displayFraction( int a = 0, int b = 1 )
{
    cout << a << "/" << b;
}

int gcd( int a, int b )
{
    if( a <= 0 || b <= 0 )
        return -1;
    int i;

    if( a > b )
        i = b;
    else if( a < b )
        i = a;

    for( ; !(a % i) && !(b % i); i-- )
       ;

   return i; 
}

bool reduceFraction( int &num, int &denom )
{
    if( num <= 0 || denom <= 0 )
        return false;

    int divisor = gcd( num, denom );
    num /= divisor;
    denom /= divisor;

    return true;
}
