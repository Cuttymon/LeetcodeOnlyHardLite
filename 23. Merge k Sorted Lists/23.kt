class Solution {
    fun mergeKLists(lists: Array<ListNode?>): ListNode? {
        if (lists.isEmpty()) return null
        val dummy = ListNode(-1)
        var p: ListNode? = dummy
        val pq = PriorityQueue(
            lists.size
        ) { a: ListNode?, b: ListNode? -> a!!.`val` - b!!.`val` }
        for (head in lists) {
            if (head != null) pq.add(head)
        }
        while (!pq.isEmpty()) {
            val node = pq.poll()
            p!!.next = node
            if (node!!.next != null) {
                pq.add(node.next)
            }
            p = p.next
        }
        return dummy.next
    }
}