#include <iostream>
using namespace std;

// Function to check if a player has won
bool isWinner(char board[3][3], char c) {
    // Check all rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == c && board[i][1] == c && board[i][2] == c) || // row
            (board[0][i] == c && board[1][i] == c && board[2][i] == c))   // column
            return true;
    }

    // Check diagonals
    if ((board[0][0] == c && board[1][1] == c && board[2][2] == c) || // main diagonal
        (board[0][2] == c && board[1][1] == c && board[2][0] == c))   // anti-diagonal
        return true;

    return false;
}

// Function to validate the board state
bool isValidBoard(char board[3][3]) {
    int xCount = 0, oCount = 0;

    // Count X and O
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') xCount++;
            else if (board[i][j] == 'O') oCount++;
        }

    // X goes first, so xCount must be equal or 1 more than oCount
    if (!(xCount == oCount || xCount == oCount + 1))
        return false;

    // If O wins, X must not also win and both counts must be equal
    if (isWinner(board, 'O')) {
        if (isWinner(board, 'X')) return false;
        return xCount == oCount;
    }

    // If X wins, xCount must be oCount + 1
    if (isWinner(board, 'X') && xCount != oCount + 1)
        return false;

    return true;
}

// Driver code
int main() {
    char board[3][3] = {
        {'X', 'X', 'O'},
        {'O', 'O', 'X'},
        {'X', 'O', 'X'}
    };

    cout << "Tic Tac Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }

    cout << "\nResult: ";
    if (isValidBoard(board))
        cout << "Given board is valid.\n";
    else
        cout << "Given board is not valid.\n";

    return 0;
}
