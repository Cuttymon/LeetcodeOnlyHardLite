import kotlin.math.max

class Solution {
    fun longestValidParentheses(s: String): Int {
        var res = 0
        val stack = Stack<Int>()
        stack.push(-1)
        for (i in s.indices) {
            if (s[i] == '(') {
                stack.push(i)
            } else {
                stack.pop()
                if (stack.empty()) {
                    stack.push(i)
                } else {
                    res = max(res, i - stack.peek())
                }
            }
        }
        return res
    }
}