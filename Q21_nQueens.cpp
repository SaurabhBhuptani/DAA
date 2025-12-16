#include <bits/stdc++.h>
using namespace std;

class NQueensSolver
{
public:
    // Recursive backtracking function
    void placeQueens(int col, vector<string> &board, int n,
                     vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal,
                     vector<vector<string>> &solutions)
    {
        // If all queens are placed
        if (col == n)
        {
            solutions.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0)
            {
                // Place queen
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recur for next column
                placeQueens(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, solutions);

                // Backtrack
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    // Function to solve N-Queens problem
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

        placeQueens(0, board, n, leftRow, upperDiagonal, lowerDiagonal, solutions);
        return solutions;
    }
};

int main()
{
    int n = 4;
    NQueensSolver solver;
    vector<vector<string>> result = solver.solveNQueens(n);

    cout << "All possible solutions for " << n << "-Queens:\n\n";
    for (auto &board : result)
    {
        for (auto &row : board)
        {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}