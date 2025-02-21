// C++GameOfLIfe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;

#include <vector>
#include <iostream>

class Solution 
{
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int rows = (int)board.size();
        int cols = (int)board[0].size();

        vector<vector<int>> directions = 
        { 
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} 
        };

        vector<vector<int>> copyOfBoard = board;

        for (int row = 0; row < rows; ++row) 
        {
            for (int col = 0; col < cols; ++col) 
            {
                int liveNeighbors = 0;

                for (auto dir : directions) 
                {
                    int r = row + dir[0];
                    int c = col + dir[1];

                    if (r >= 0 && r < rows && c >= 0 && c < cols && copyOfBoard[r][c] == 1) 
                    {
                        ++liveNeighbors;
                    }
                }

                if (copyOfBoard[row][col] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) 
                {
                    board[row][col] = 0;
                }
                if (copyOfBoard[row][col] == 0 && liveNeighbors == 3) 
                {
                    board[row][col] = 1;
                }
            }
        }
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> board =
    {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    sol.gameOfLife(board);

    for (const auto& row : board)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
