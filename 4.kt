class Solution {
    fun findMedianSortedArrays(nums1: IntArray, nums2: IntArray): Double {
        val m = nums1.size
        val n = nums2.size

        if (n < m) {
            return findMedianSortedArrays(nums2, nums1)
        }
        var l = 0
        var r = m
        val tl = ((n + m + 1) shr 1).toInt()
        while (l < r) {
            var i = ((l + r) shr 1).toInt()
            var j = tl - i
            if (nums1[i] < nums2[j - 1]) {
                l = i + 1
            } else {
                r = i
            }
        }
        val i = l
        val j = tl - l
        val leftmax = maxOf(if (i == 0) Int.MIN_VALUE else nums1[i - 1], if (j == 0) Int.MIN_VALUE else nums2[j - 1])
        if ((n + m) % 2 == 1) {
            return leftmax.toDouble()
        }
        val rightmin = minOf(if (i == m) Int.MAX_VALUE else nums1[i], if (j == n) Int.MAX_VALUE else nums2[j])
        return (leftmax + rightmin) * 0.5
    }
}