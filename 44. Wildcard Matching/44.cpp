class Solution
{
public:
    vector<vector<int>> memo;
    bool isMatch(string s, string p)
    {
        if (p.empty())
            return s.empty();                                             //都为空则匹配，都匹配完了，返回true,如果p匹配完了，s还没匹配完，则返回false
        string pp = remove_repeat_star(p);                                //去除重复的*，因为多个*和一个*的匹配是一样的
        memo = vector<vector<int>>(s.size(), vector<int>(pp.size(), -1)); //初始化备忘录
        return dp(s, 0, pp, 0);                                           // 定义：判断 s[i..] 是否能被 p[j..] 匹配
    }
    string remove_repeat_star(string p)
    {
        if (p.empty())
            return "";
        string res = "";
        res.push_back(p[0]);
        for (int i = 1; i < p.size(); i++)
        {
            if (p[i] == '*' && p[i - 1] == '*') //上一个字符是*，则不加入
                continue;
            res.push_back(p[i]);
        }
        return res;
    }
    bool dp(string &s, int i, string &pp, int j)
    {
        if (j == pp.size() && i == s.size()) //如果两边都到了末尾，则匹配成功
            return true;
        if (i == s.size())
        {
            for (int k = j; k < pp.size(); k++) //如果s遍历完，且p后面出现非*，则匹配失败
            {
                if (pp[k] != '*')
                    return false;
            }
            return true;
        }
        if (j == pp.size()) //在后面没有*的情况下，p到头了，s有剩余，则匹配失败
            return false;
        if (memo[i][j] != -1) //如果已经计算过，则直接返回
            return bool(memo[i][j]);
        bool ans = false;
        if (pp[j] == '?' || pp[j] == s[i])
        {
            ans = dp(s, i + 1, pp, j + 1); //如果p的当前字符是?或者s的当前字符和p的当前字符相等，则匹配下一个
        }
        else if (pp[j] == '*')
        {
            ans = dp(s, i + 1, pp, j) || dp(s, i, pp, j + 1); //如果p的当前字符是*，则可以匹配0个，也可以匹配多个
        }
        memo[i][j] = ans;
        return ans;
    }
};