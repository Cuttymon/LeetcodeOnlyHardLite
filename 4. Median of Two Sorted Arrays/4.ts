function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    const m = nums1.length;
    const n = nums2.length;
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }
    var iMin = 0, iMax = m;
    const k = (m + n + 1) >> 1;
    while (iMin < iMax) {
        var i: number = (iMin + iMax) >> 1;
        var j: number = k - i;
        if (nums1[i] < nums2[j - 1]) {
            iMin = i + 1
        }
        else {
            iMax = i
        }
    };
    i = iMin;
    j = k - i;
    const maxLeft = Math.max(i == 0 ? -Infinity : nums1[i - 1], j == 0 ? -Infinity : nums2[j - 1]);
    if ((m + n) % 2 === 1) {
        return maxLeft;
    }
    const minRight = Math.min(i == m ? Infinity : nums1[i], j == n ? Infinity : nums2[j]);
    return (maxLeft + minRight) / 2;
}