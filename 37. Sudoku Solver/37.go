func solveSudoku(board [][]byte) {
	solve(board, 0, 0)
}
func solve(board [][]byte, row, col int) bool {
	if row == 9 {
		return true
	}
	if col == 9 {
		return solve(board, row+1, 0)
	}
	if board[row][col] != '.' {
		return solve(board, row, col+1)
	}
	for i := 1; i <= 9; i++ {
		if isValid(board, row, col, byte(i)+'0') {
			board[row][col] = byte(i) + '0'
			if solve(board, row, col+1) {
				return true
			}
		}
	}
	board[row][col] = '.'
	return false
}
func isValid(board [][]byte, row, col int, num byte) bool {
	for i := 0; i < 9; i++ {
		if board[row][i] == num || board[i][col] == num || board[row/3*3+i/3][col/3*3+i%3] == num {
			return false
		}
	}
	return true
}