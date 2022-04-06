//改自https://zhenchaogan.gitbook.io/leetcode-solution/leetcode-30-substring-with-concatenation-of-all-words
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        // base case
        if (words.empty())
            return vector<int>();
        vector<int> res;
        unordered_map<string, int> dict;
        int len = words[0].size();
        int n = s.length(), m = words.size();
        //将words中的单词放入dict中
        for (const string &word : words)
            dict[word]++;
        //只需经历字符串长度次遍历即可
        for (int i = 0; i < len; i++)
        {
            int cnt = 0;                            //初始化计算点为0，当cnt为m时，说明找到了符合要求的子串
            unordered_map<string, int> copy = dict; //临时字典初始化为dict
            for (int j = i; j <= n - len; j += len)
            {
                string sub = s.substr(j, len);
                copy[sub]--;        // copy“吃进”sub，则减1
                if (copy[sub] >= 0) //如过还是大于等于0，则代表sub为有用字符串，cnt加1
                    cnt++;
                int pop_start = j - m * len; //滑动窗口左边的位置，右边为j
                if (pop_start >= 0)          //当pop_start大于等于0时，说明有可以滑动的窗口
                {
                    string pop = s.substr(pop_start, len);
                    copy[pop]++;       //滑动窗口左边的位置的字符串，copy“吐出”pop，加1
                    if (copy[pop] > 0) //如果copy中还有pop，说明pop为有用字符串，cnt减1
                        cnt--;
                }
                if (cnt == m) //当cnt为m时，说明找到了符合要求的子串
                {
                    res.push_back(pop_start + len); //结果加进
                }
            }
        }
        return res;
    }
};