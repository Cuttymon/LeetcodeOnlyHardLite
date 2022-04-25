class Solution
{
public:
    map<string, bool> memo;
    bool isMatch(string s, string p)
    {
        return dp(s, 0, p, 0);
    }
    // 动态规划
    bool dp(string &s, int i, string &p, int j)
    {
        int m = s.size(), n = p.size();
        // 基本情况
        if (j == n)
            return i == m;
        if (i == m)
        {
            if ((n - j) % 2 == 1)
            {
                return false;
            }
            for (; j + 1 < n; j += 2)
            {
                if (p[j + 1] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        // 已经计算过
        string key = to_string(i) + "," + to_string(j);
        // 查找备忘录
        if (memo.count(key))
            return memo[key];
        bool ans = false;
        if (p[j] == '.' || p[j] == s[i])
        {
            if (j + 1 < n && p[j + 1] == '*')
            {
                ans = dp(s, i + 1, p, j) || dp(s, i, p, j + 2);
            }
            else
            {
                ans = dp(s, i + 1, p, j + 1);
            }
        }
        else
        {
            if (j + 1 < n && p[j + 1] == '*')
            {
                ans = dp(s, i, p, j + 2);
            }
            else
            {
                return false;
            }
        }
        memo[key] = ans;
        return ans;
    }
};