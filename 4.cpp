class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        // 让nums1的长度小于nums2的长度
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        // 将左边的长度设置为偶数，totalleft为左边的长度
        int tl = (m + n + 1) >> 1;

        int l = 0;
        int r = m;
        // 找到左边的长度
        while (l < r)
        {
            int i = (r + l) >> 1;
            int j = tl - i;
            // i和j越界，说明不是要找的位置
            if (nums1[i] < nums2[j - 1])
                l = i + 1;
            else
                r = i;
        }

        int i = l;
        int j = tl - l;
        //  避免越界，所以如果为边界，则取无限大或小的数
        int c1 = max(i == 0 ? INT_MIN : nums1[i - 1],
                           j == 0 ? INT_MIN : nums2[j - 1]);
        // 如果是偶数，则取两个数的平均值
        if ((m + n) % 2 == 1)
            return c1;

        int c2 = min(i == m ? INT_MAX : nums1[i],
                           j == n ? INT_MAX : nums2[j]);

        return (c1 + c2) * 0.5;
    }
};