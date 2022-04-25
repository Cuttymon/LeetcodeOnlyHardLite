class Solution {
    fun trap(height: IntArray): Int {
        var left = 0
        var right = height.size - 1
        var ans = 0
        var left_max = height[left]
        var right_max = height[right]
        while (left < right) {
            if (left_max < right_max) {
                ans += left_max - height[left++]
                left_max = if (left_max > height[left]) left_max else height[left]
            } else {
                ans += right_max - height[right--]
                right_max = if (right_max > height[right]) right_max else height[right]
            }
        }
        return ans
    }
}
