#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<int> &board, int row, int col)
{
  // Check if there is a queen in the same column
  for (int i = 0; i < row; ++i)
  {
    if (board[i] == col ||           // Same column
        board[i] - i == col - row || // Same diagonal (left-top to right-bottom)
        board[i] + i == col + row)
    { // Same diagonal (right-top to left-bottom)
      return false;
    }
  }
  return true;
}

void printBoard(const vector<int> &board)
{
  int n = board.size();
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cout << (board[i] == j ? "Q" : ".");
    }
    cout << endl;
  }
  cout << endl;
}

void solveNQueens(vector<int> &board, int row, int n)
{
  if (row == n)
  {
    // All queens are placed successfully, print the board
    printBoard(board);
    return;
  }

  for (int col = 0; col < n; ++col)
  {
    if (isSafe(board, row, col))
    {
      board[row] = col; // Place the queen

      // Recur to place the rest of the queens
      solveNQueens(board, row + 1, n);

      // Backtrack
      board[row] = -1;
    }
  }
}

int main()
{
  int n = 4;                // Change this value for different board sizes
  vector<int> board(n, -1); // Initialize the board with no queens placed

  solveNQueens(board, 0, n);

  return 0;
}
