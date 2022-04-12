class Solution {
    fun firstMissingPositive(nums: IntArray): Int {
        val n = nums.size
        if (n == 0) return 1
        for (i in 0 until n) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                val temp = nums[i]
                nums[i] = nums[temp - 1]
                nums[temp - 1] = temp
            }
        }
        for (i in 0 until n) {
            if (nums[i] != i + 1) return i + 1
        }
        return n + 1
    }
}
