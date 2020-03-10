### 36. Valid Sudoku

题目说的很清楚，在三个条件内不能有重复的数字，前两种判断都很容易，第三种判断不容易想，在3X3的子盒子里不能有重复的，可以观察到在每一个子盒子中row/3和col/3都是与其它子盒子不同的，所以可以利用这点

```
bool isValidSudoku(std::vector<std::vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();
    std::vector<std::string> rows;
    std::vector<std::string> cols;
    std::vector<std::string> subs;

    for (int i = 0; i != m; ++i)
    {
        for (int j = 0; j != n; ++j)
        {
            if (board[i][j] == ' ')
                continue;
            else
            {
                std::string r = to_string(i);
                std::string c = to_string(j);
                std::string row = r + board[i][j];
                if (std::find(rows.begin(), rows.end(), row) == rows.end())
                    rows.push_back(row);
                else
                    return false;
                std::string col = c + board[i][j];
                if (std::find(cols.begin(), cols.end(), col) == cols.end())
                    cols.push_back(col);
                else
                    return false;
                r = to_string(i / 3);
                c = to_string(j / 3);
                std::string sub = r + c + board[i][j];
                if (std::find(subs.begin(), subs.end(), sub) == subs.end())
                    subs.push_back(sub);
                else
                    return false;
            }
        }
    }
    return true;
}

```
