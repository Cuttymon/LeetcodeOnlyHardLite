func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil {
		return nil
	}
	node := head
	for i := 0; i < k; i++ {
		if node == nil {
			return head
		}
		node = node.Next
	}
	newHead := reverse(head, node)
	head.Next = reverseKGroup(node, k)
	return newHead
}
func reverse(a *ListNode, b *ListNode) *ListNode {
	prev := b
	for a != b {
		next := a.Next
		a.Next = prev
		prev = a
		a = next
	}
	return prev
}