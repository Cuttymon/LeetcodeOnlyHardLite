class Solution:

    def trap(self, height: List[int]) -> int:
        ans, left, right = 0, 0, len(height) - 1
        while left < right:
            i = 1
            if height[left] < height[right]:
                while height[left] > height[left + i]:
                    ans += height[left] - height[left + i]
                    i += 1
                left += i
            else:
                while height[right] > height[right - i]:
                    ans += height[right] - height[right - i]
                    i += 1
                right -= i
        return ans
