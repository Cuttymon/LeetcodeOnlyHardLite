//改自https://books.halfrost.com/leetcode/ChapterFour/0001~0099/0032.Longest-Valid-Parentheses/
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stack;
        stack.push(-1); //初始化-1让左边有个起点，当第一个为')'时，可以抵掉
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') //遇到'('，压栈
            {
                stack.push(i);
            }
            else //遇到')'，弹栈
            {
                stack.pop();
                if (stack.empty()) //如果栈空，说明这个')'是无效的，记录下起点
                {
                    stack.push(i);
                }
                else //如果栈不空，说明这个')'是有效的，计算长度
                {
                    res = max(res, i - stack.top());
                }
            }
        }
        return res;
    }
};
