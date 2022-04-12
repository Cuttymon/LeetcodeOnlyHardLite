class Solution
{
public:
    // 判断 board[i][j] 是否可以填入 num
    bool isValid(vector<vector<char>> &board, int row, int col, char num)
    {
        for (int i = 0; i < 9; i++)
        {
            // board[row][i] == num判断行是否有重复，board[i][col] == num判断列是否有重复，board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == num判断3*3的区域是否有重复
            if (board[row][i] == num || board[i][col] == num || board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == num)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board, int row, int col)
    {
        // 穷举到最后一列的话就换到下一行重新开始。
        if (row == 9)
            return true;
        // 找到一个可行解，结束递归
        if (col == 9)
            return solve(board, row + 1, 0);
        // 如果当前位置已经有值，就继续判断下一个位置
        if (board[row][col] != '.')
            return solve(board, row, col + 1);
        for (char k = '1'; k <= '9'; k++)
        {
            // 判断 board[i][j] 是否可以填入 num
            if (isValid(board, row, col, k))
            {
                // 填入，并继续判断下一个位置
                board[row][col] = k;
                if (solve(board, row, col + 1))
                    return true;
            }
        }
        // 撤销填入的值，回溯
        board[row][col] = '.';
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board, 0, 0);
    }
};