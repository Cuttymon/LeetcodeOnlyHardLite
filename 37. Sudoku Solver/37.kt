class Solution {
    fun solveSudoku(board: Array<CharArray>) {
        solve(board, 0, 0)
    }

    private fun solve(board: Array<CharArray>, row: Int, col: Int): Boolean {
        if (row == 9) return true
        if (col == 9) return solve(board, row + 1, 0)
        if (board[row][col] != '.') return solve(board, row, col + 1)

        for (i in '1'..'9') {
            if (isValid(board, row, col, i)) {
                board[row][col] = i
                if (solve(board, row, col + 1)) return true
            }
        }
        board[row][col] = '.'
        return false
    }

    private fun isValid(board: Array<CharArray>, row: Int, col: Int, num: Char): Boolean {
        for (i in 0..8) {
            if (board[row][i] == num || board[i][col] == num || board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == num) return false
        }
        return true
    }
}
