class Solution:

    def mergeKLists(self,
                    lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        length = len(lists)
        if length < 1:
            return None
        if length == 1:
            return lists[0]
        mid = length // 2
        left = self.mergeKLists(lists[:mid])
        right = self.mergeKLists(lists[mid:])
        return self.merge(left, right)

    def merge(self, left: Optional[ListNode],
              right: Optional[ListNode]) -> Optional[ListNode]:
        if left is None:
            return right
        if right is None:
            return left
        if left.val < right.val:
            left.next = self.merge(left.next, right)
            return left
        right.next = self.merge(left, right.next)
        return right
