class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 1;
        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) //大于0，小于等于n，不等于自己
            {
                //交换位置
                int tmp = nums[i];
                nums[i] = nums[tmp - 1];
                nums[tmp - 1] = tmp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1) //找到第一个不等于自己的数
                return i + 1;
        }
        return n + 1; //所有数都等于自己，即1,2,3,...,n，返回n+1
    }
};