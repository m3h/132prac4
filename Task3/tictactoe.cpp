#include <iostream>

using namespace std;

#define TIE 0
#define MAXTURNS 9

int checkDiagonals( char board[3][3] );
void printBoard( char board[3][3] );

int main()
{
    char board[3][3];
    int turnsTaken = 0;
    for( int i = 0; i < 3; i++ )
        for( int j = 0; j < 3; j++ )
         board[i][j] = '*';

    cout << "### TIC TAC TOE GAME ###" << endl
        << endl;

    int winner = 0;
    short player = 1;
    for( int turnsTaken = 0; turnsTaken < MAXTURNS && !winner; turnsTaken++ )
    {
        short row, column;

        do
        {

            printBoard( board );

            cout << "Player " << player << ": Enter your move in the format <row><column>: ";
            cin >> row >> column;
            cout << endl;

            --row;  // correct for array subscript
            --column;
         } while( row > 2 || row < 0 || column > 2 || column < 0 || board[row][column] != '*' );

        if( player == 1 )
        {
            board[row][column] = 'X';
            player = 2;
        } else if ( player == 2 )
        {
            board[row][column] = 'O';
            player = 1;
        }

        winner = checkDiagonals( board );

        for( int i = 0; i < 3; i++ )
        {
            int hits1 = 0;
            int hits2 = 0;
            for(char val: board[i] )
                if( val == 'X' )
                    ++hits1;
                else if( val == 'O' )
                    ++hits2;

            if( hits1 == 3 )
                winner = 1;
            else if( hits2 == 3 )
                winner = 2;
        }
        
        for( int i = 0; i < 3; i++)
        {
            int hits1 = 0;
            int hits2 = 0;
            for( int j = 0; j < 3; j++ )
            {
                if( board[j][i] == 'X' )
                    ++hits1;
                else if( board[j][i] == 'O' )
                    ++hits2;
            }

            if( hits1 == 3 )
                winner = 1;
            else if( hits2 == 3 )
                winner = 2;
        }

    }

    printBoard( board );

    if( winner == TIE )
        cout << "There has been a tie!" << endl;
    else
        cout << "Player " << winner << " has won!" << endl;

    return 0;
}

int checkDiagonals( char board[3][3] )
{
    if( board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' )
        return 1;
    else if( board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X' )
        return 1;
    else if( board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' )
        return 2;
    else if( board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O' )
        return 2;

    return 0;
}

void printBoard( char board[3][3] )
{
    for( int i = 0; i < 3; i++ )
    {
        for( char val: board[i] )
            cout << val << " ";
        cout << endl;
    }
    cout << endl;
}
