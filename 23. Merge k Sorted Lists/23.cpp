class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        //基本情况
        if (lists.size() == 0)
            return nullptr;
        //大小堆
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto l : lists)
        {
            while (l)
            {
                q.push(l->val);
                l = l->next;
            }
        }
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (!q.empty())
        {
            p->next = new ListNode(q.top());
            p = p->next;
            q.pop();
            if (p->next)
                q.push(p->next->val);
        }
        return head->next;
    }
};