#include <iostream>
using namespace std;

int board[10]; // board[row] = column position of queen

// Function to check whether queen can be placed safely
bool isSafe(int row, int col)
{
    for(int i = 1; i < row; i++)
    {
        // Check same column
        if(board[i] == col)
            return false;

        // Check diagonal
        if(abs(board[i] - col) == abs(i - row))
            return false;
    }

    return true;
}

// Function to place queens
void solve(int row, int n)
{
    // If all queens are placed
    if(row > n)
    {
        cout << "\nSolution:\n";

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(board[i] == j)
                    cout << " Q ";
                else
                    cout << " - ";
            }
            cout << endl;
        }

        return;
    }

    // Try placing queen in every column
    for(int col = 1; col <= n; col++)
    {
        // Check if position is safe
        if(isSafe(row, col))
        {
            board[row] = col;   // Place queen

            solve(row + 1, n);  // Move to next row
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    solve(1, n);

    return 0;
}