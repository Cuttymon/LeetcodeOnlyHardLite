class Solution:

    def isMatch(self, s: str, p: str) -> bool:
        self.memo = {}
        return self.dp(s, 0, p, 0)

    def dp(self, s: str, i: int, p: str, j: int) -> bool:
        m, n = len(s), len(p)
        if j == n:
            return i == m
        if i == m:
            if (n - j) % 2 == 1:
                return False
            while j < n - 1:
                if p[j + 1] != '*':
                    return False
                j += 2
            return True
        key = str(i) + str(j)
        if key in self.memo:
            return self.memo[key]
        self.ans = False
        if p[j] == '.' or p[j] == s[i]:
            if j < n - 1 and p[j + 1] == '*':
                self.ans = self.dp(s, i + 1, p, j) or self.dp(s, i, p, j + 2)
            else:
                self.ans = self.dp(s, i + 1, p, j + 1)
        else:
            if j < n - 1 and p[j + 1] == '*':
                self.ans = self.dp(s, i, p, j + 2)
            else:
                return False
        self.memo[key] = self.ans
        return self.ans
