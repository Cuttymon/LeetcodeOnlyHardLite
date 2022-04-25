class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = height[left], right_max = height[right]; //初始化左右最大值
        while (left < right)                                    //左右指针同时向中间移动
        {
            if (left_max < right_max) //左边最大值小于右边最大值，左边指针向右移动
            {
                ans += left_max - height[left++];       //增加水的份数
                left_max = max(left_max, height[left]); //更新左边最大值
            }
            else //右边最大值小于左边最大值，右边指针向左移动
            {
                ans += right_max - height[right--];        //增加水的份数
                right_max = max(right_max, height[right]); //更新右边最大值
            }
        }
        return ans;
    }
};