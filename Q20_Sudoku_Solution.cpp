#include <bits/stdc++.h>
using namespace std;

// Check if placing num at board[row][col] is valid
bool isSafe(int board[9][9], int row, int col, int num)
{
    // Check row
    for (int j = 0; j < 9; j++)
        if (board[row][j] == num)
            return false;

    // Check column
    for (int i = 0; i < 9; i++)
        if (board[i][col] == num)
            return false;

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = startRow; i < startRow + 3; i++)
        for (int j = startCol; j < startCol + 3; j++)
            if (board[i][j] == num)
                return false;

    return true;
}

// Backtracking solver
bool solveSudoku(int board[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(board, row, col, num))
                    {
                        board[row][col] = num;
                        if (solveSudoku(board))
                            return true;
                        board[row][col] = 0; // Backtrack
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true; // All cells filled
}

// Print the Sudoku board
void printBoard(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0 && j != 8)
                cout << "| ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i != 8)
            cout << "---------------------" << endl;
    }
}

int main()
{
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solveSudoku(board))
    {
        cout << "Sudoku Solved:" << endl;
        printBoard(board);
    }
    else
    {
        cout << "No solution exists!" << endl;
    }

    return 0;
}