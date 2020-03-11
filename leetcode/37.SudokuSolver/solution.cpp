#include <iostream>
#include <vector>

bool check(std::vector<std::vector<char>> &board, int x, int y, char c)
{
    int row = x - x % 3;
    int col = y - y % 3;
    for (int i = 0; i != 9; ++i)
        if (board[x][i] == c)
            return false;
    for (int i = 0; i != 9; ++i)
        if (board[i][y] == c)
            return false;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[row + i][col + j] == c)
                return false;
    return true;
}

bool solve(std::vector<std::vector<char>> &board, int i, int j)
{
    if (i == 9)
        return true;
    if (j == 9)
        return solve(board, i + 1, 0);
    if (board[i][j] != '.')
        return solve(board, i, j + 1);
    for (char c = '1'; c <= '9'; ++c)
    {
        if (check(board, i, j, c))
        {
            board[i][j] = c;
            if (solve(board, i, j + 1))
                return true;
            else
                board[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(std::vector<std::vector<char>> &board)
{
    solve(board, 0, 0);
}
