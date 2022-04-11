class Solution:

    def solveSudoku(self, board: List[List[str]]) -> None:
        self.solve(board, 0, 0)

    def solve(self, board: List[List[str]], row: int, col: int) -> bool:
        if row == 9:
            return True
        if col == 9:
            return self.solve(board, row + 1, 0)
        if board[row][col] != '.':
            return self.solve(board, row, col + 1)
        for i in range(1, 10):
            if self.isValid(board, row, col, str(i)):
                board[row][col] = str(i)
                if self.solve(board, row, col + 1):
                    return True
        board[row][col] = '.'
        return False

    def isValid(self, board: List[List[str]], row: int, col: int,
                num: str) -> bool:
        for i in range(9):
            if board[row][i] == num or board[i][col] == num or board[
                (row // 3) * 3 + i // 3][(col // 3) * 3 + i % 3] == num:
                return False
        return True
