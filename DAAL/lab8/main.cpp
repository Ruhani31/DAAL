#include <iostream>
using namespace std;

void printSolution(int** board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << "- ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int** board, int row, int col, int N) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueensUtil(int** board, int row, int N) {
    if (row == N) {
        printSolution(board, N);
        return true;
    }

    bool foundSolution = false;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;

            foundSolution = solveNQueensUtil(board, row + 1, N) || foundSolution;

            board[row][col] = 0;
        }
    }

    return foundSolution;
}

void solveNQueens(int N) {
    // Dynamically allocate memory for the board
    int** board = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N]();  // Initialize all elements to 0
    }

    if (!solveNQueensUtil(board, 0, N))
        cout << "No solution exists" << endl;

    // Deallocate the memory after usage
    for (int i = 0; i < N; i++) {
        delete[] board[i];
    }
    delete[] board;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    solveNQueens(N);

    return 0;
}
