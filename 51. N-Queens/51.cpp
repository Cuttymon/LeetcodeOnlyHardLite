class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.')); //初始化nxn皇后棋盘
        vector<vector<string>> res;
        backtrack(board, 0, res);
        return res;
    }
    void backtrack(vector<string> &board, int row, vector<vector<string>> &res)
    {
        if (row == board.size()) //遍历完成，结束
        {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); col++)
        {
            if (isValid(board, row, col)) //判断是否合法
            {
                board[row][col] = 'Q';          //放置皇后
                backtrack(board, row + 1, res); //递归回溯
                board[row][col] = '.';          //保存好答案后，撤销选择，恢复原来的状态
            }
        }
    }

    bool isValid(vector<string> &board, int row, int col)
    {
        for (int i = 0; i < row; i++) //判断是否在同一列
        {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) //左上的延伸查看有无皇后
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) //右上的延伸查看有无皇后
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};