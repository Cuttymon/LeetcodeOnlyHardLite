class Solution {
    fun reverseKGroup(head: ListNode?, k: Int): ListNode? {
        if (head == null) return null
        val a: ListNode
        var b: ListNode?
        b = head
        a = b
        for (i in 0 until k) {
            if (b == null) return head
            b = b.next
        }
        val newHead = reverse(a, b)
        a.next = reverseKGroup(b, k)
        return newHead
    }

    private fun reverse(a: ListNode?, b: ListNode?): ListNode? {
        var pre: ListNode?
        var cur: ListNode?
        var nxt: ListNode?
        pre = null
        cur = a
        while (cur != b) {
            nxt = cur!!.next
            cur.next = pre
            pre = cur
            cur = nxt
        }
        return pre
    }
}