func trap(height []int) int {
	ans, left, right := 0, 0, len(height)-1
	for left < right {
		i := 1
		if height[left] < height[right] {
			for height[left] > height[left+i] {
				ans += height[left] - height[left+i]
				i++
			}
			left += i
		} else {
			for height[right] > height[right-i] {
				ans += height[right] - height[right-i]
				i++
			}
			right -= i
		}
	}
	return ans
}