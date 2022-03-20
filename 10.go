func isMatch(s string, p string) bool {
	memo := make(map[string]bool)
	return dp(s, 0, p, 0, memo)
}

func dp(s string, i int, p string, j int, memo map[string]bool) bool {
	m, n := len(s), len(p)
	if j == n {
		return i == m
	}
	if i == m {
		if (n-j)%2 == 1 {
			return false
		}
		for ; j+1 < n; j += 2 {
			if p[j+1] != '*' {
				return false
			}
		}
		return true
	}
	key := fmt.Sprintf("%d,%d", i, j)
	if v, ok := memo[key]; ok {
		return v
	}
	ans := false
	if p[j] == '.' || p[j] == s[i] {
		if (j+1) < n && p[j+1] == '*' {
			ans = dp(s, i+1, p, j, memo) || dp(s, i, p, j+2, memo)
		} else {
			ans = dp(s, i+1, p, j+1, memo)
		}
	} else {
		if (j+1) < n && p[j+1] == '*' {
			ans = dp(s, i, p, j+2, memo)
		} else {
			return false
		}
	}
	memo[key] = ans
	return ans
}