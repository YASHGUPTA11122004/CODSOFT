#include <iostream>
#include <vector>
using namespace std;

const int boardsize = 3;
vector<vector<char>> board(boardsize, vector<char>(boardsize, ' '));

void displayBoard() 
{
    cout << "Current Board:" << endl;
    for (int i = 0; i < boardsize; ++i) 
    {
        for (int j = 0; j < boardsize; ++j) 
        {
            cout << board[i][j];
            if (j < boardsize - 1) cout << " | ";
        }
        cout << endl;
        if (i < boardsize - 1) cout << "---------" << endl;
    }
}

bool isWin(char player) 
{
    for (int i = 0; i < boardsize; ++i) 
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool isDraw() 
{
    for (int i = 0; i < boardsize; ++i) 
    {
        for (int j = 0; j < boardsize; ++j) 
        {
            if (board[i][j] == ' ') 
              return false;
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer) 
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void resetBoard() 
{
    for (int i = 0; i < boardsize; ++i) 
    {
        for (int j = 0; j < boardsize; ++j) 
        {
            board[i][j] = ' ';
        }
    }
}

void playGame() 
{
    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver)
    {
        displayBoard();
        int row, col;

        cout << "Player " << currentPlayer << ", Enter your move (row and column): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') 
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row-1][col-1] = currentPlayer;

        if (isWin(currentPlayer)) 
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        }
        else if (isDraw()) 
        {
            displayBoard();
            cout << "The game is a draw!" << endl;
            gameOver = true;
        } 
        else 
        {
            switchPlayer(currentPlayer);
        }
    }
}

int main() 
{
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') 
    {
        resetBoard();
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    return 0;
}
