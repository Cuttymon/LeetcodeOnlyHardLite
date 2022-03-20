class Solution {
    fun isMatch(s: String, p: String): Boolean {
        val memo = mutableMapOf<String, Boolean>()
        fun dp(i: Int, j: Int): Boolean {
            var k = j
            val m = s.length
            val n = p.length
            if (k == n) return i == m
            if (i == m) {
                if (((n - k) % 2) == 1) {
                    return false
                }
                while (k < n - 1) {
                    if (p[k + 1] != '*') {
                        return false
                    }
                    k += 2
                }
                return true
            }
            val key="$i$k"
            if (memo.containsKey(key)) {
                return memo[key]!!
            }
            var ans = false
            ans = if (p[k] == '.' || p[k] == s[i]) {
                if (j + 1 < n && p[k + 1] == '*') {
                    dp(i + 1, k) || dp(i, k + 2);
                } else {
                    dp(i + 1, k + 1);
                }
            } else {
                if (j + 1 < n && p[k + 1] == '*') {
                    dp(i, k + 2);
                } else {
                    false;
                }
            }
            memo[key] = ans;
            return ans;
        }
        return dp(0, 0)
    }
}