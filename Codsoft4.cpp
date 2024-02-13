#include <iostream>
using namespace std;
void displayBoard(char board[3][3]) 
{
    for (int i = 0; i < 3; ++i) 
	{
        for (int j = 0; j < 3; ++j) 
		{
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool checkWin(char board[3][3], char player)
 {
    for (int i = 0; i < 3; ++i) 
	{
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

int main() 
{
    char board[3][3] = {  { ' ', ' ', ' ' },
                          { ' ', ' ', ' ' },
                          { ' ', ' ', ' ' }  };

    char currentPlayer = 'X';

    do 
	{
        cout << "Current Board:\n";
        displayBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') 
		{
            board[row][col] = currentPlayer;
            if (checkWin(board, currentPlayer)) 
			{
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } 
		else 
		{
            cout << "Invalid move. The cell is already occupied or out of bounds. Try again.\n";
        }

    } 
	while (true);
    cout << "Final Board:\n";
    displayBoard(board);
}

