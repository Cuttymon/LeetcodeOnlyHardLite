func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	m, n := len(nums1), len(nums2)
	if m > n {
		return findMedianSortedArrays(nums2, nums1)
	}
	l, r, half := 0, m, (m+n+1)>>1
	for l < r {
		i := (l + r) >> 1
		j := half - i
		if nums1[i] < nums2[j-1] {
			l = i + 1
		} else {
			r = i
		}
	}
	i := l
	j := half - i
	var maxLeft float64
	if i == 0 {
		maxLeft = float64(nums2[j-1])
	} else if j == 0 {
		maxLeft = float64(nums1[i-1])
	} else {
		maxLeft = float64(max(nums1[i-1], nums2[j-1]))
	}

	if (m+n)%2 == 1 {
		return maxLeft
	}
	var minRight float64
	if i == m {
		minRight = float64(nums2[j])
	} else if j == n {
		minRight = float64(nums1[i])
	} else {
		minRight = float64(min(nums1[i], nums2[j]))
	}
	return (maxLeft + minRight) / 2
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}