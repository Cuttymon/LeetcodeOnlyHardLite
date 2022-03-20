class Solution:

    def reverseKGroup(self, head: Optional[ListNode],
                      k: int) -> Optional[ListNode]:
        if head is None:
            return None
        node = head
        for i in range(0, k):
            if node is None:
                return head
            node = node.next
        newHead = self.reverse(head, node)
        head.next = self.reverseKGroup(node, k)
        return newHead

    def reverse(self, a: Optional[ListNode],
                b: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        while a != b:
            next = a.next
            a.next = prev
            prev = a
            a = next
        return prev
