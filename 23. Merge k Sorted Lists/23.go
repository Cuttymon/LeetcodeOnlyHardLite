func mergeKLists(lists []*ListNode) *ListNode {
	length := len(lists)
	//基本情况
	if length < 1 {
		return nil
	}
	if length == 1 {
		return lists[0]
	}
	//分治，两两合一
	mid := length / 2
	left := mergeKLists(lists[:mid])  //左边部分拆开直至长度为1即可返回单条子列表
	right := mergeKLists(lists[mid:]) //右边
	return reverse(left, right)
}
func reverse(left *ListNode, right *ListNode) *ListNode {
	if left == nil {
		return right
	}
	if right == nil {
		return left
	}
	//.val代表此列表的首节点指针的值
	if left.Val < right.Val {
		//.Next指向下一个，且与下一个返回的相连
		left.Next = reverse(left.Next, right)
		return left //返回至上一个循环的.Next
	}
	right.Next = reverse(left, right.Next)
	return right
}