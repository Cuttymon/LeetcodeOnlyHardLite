class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0, left = 0, right = height.size() - 1; //双指针
        while (left < right)                              //两边向中间靠拢
        {
            int i = 1;
            //挪矮的那边
            if (height[left] < height[right])
            {
                while (height[left] > height[left + i]) //中间有比目前矮的
                {
                    ans += height[left] - height[left + i]; //加上相差的水份数
                    i++;                                    //挪动幅度累加
                }
                left += i; //直接到遇到更高的时候
            }
            else
            {
                while (height[right] > height[right - i])
                {
                    ans += height[right] - height[right - i];
                    i++;
                }
                right -= i;
            }
        }
        return ans;
    }
};