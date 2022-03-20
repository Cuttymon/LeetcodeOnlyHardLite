class Solution:

    def findMedianSortedArrays(self, nums1: List[int],
                               nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        if m > n:
            return self.findMedianSortedArrays(nums2, nums1)
        l, r, tl = 0, m, int((m + n + 1) >> 1)
        while l < r:
            i = int((l + r) >> 1)
            j = tl - i
            if (nums1[i] < nums2[j - 1]):
                l = i + 1
            else:
                r = i

        i = l
        j = tl - l
        leftmax = max(
            float('-inf') if i == 0 else nums1[i - 1],
            float('-inf') if j == 0 else nums2[j - 1])
        if (m + n) % 2 == 1:
            return leftmax
        rightmin = min(
            float('inf') if i == m else nums1[i],
            float('inf') if j == n else nums2[j])
        return (leftmax + rightmin) * 0.5
