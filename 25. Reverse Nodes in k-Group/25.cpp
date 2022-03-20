class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        //基本情况
        if (head == nullptr)
            return nullptr;
        ListNode *node = head;
        for (int i = 0; i < k; i++)
        {
            if (node == nullptr)
                return head;
            //找到第一个k个节点
            node = node->next;
        }
        //翻转k个节点
        ListNode *newHead = reverse(head, node);
        //拼接
        head->next = reverseKGroup(node, k);
        return newHead; 
    }
    ListNode *reverse(ListNode *a, ListNode *b)
    {
        ListNode *prev = nullptr;
        while (a != b)
        {
            ListNode *next = a->next;
            a->next = prev;
            prev = a;
            a = next;
        }
        return prev;
    }
};