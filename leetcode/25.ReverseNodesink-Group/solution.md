### 25. Reverse Nodes In k

将tail移动到k个数的末尾，然后将前面的数一次移动到tail的next

```
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    auto pre = dummy;
    auto cur = head;
    auto tail = dummy;
    while (true)
    {
        int num = 0;
        while (tail != nullptr && num != k)
        {
            num += 1;
            tail = tail->next;
        }
        if (tail == nullptr)
            break;
        auto nhead = pre->next;
        while (pre->next != tail)
        {
            cur = pre->next;
            pre->next = cur->next;
            cur->next = tail->next;
            tail->next = cur;
        }
        pre = nhead;
        tail = nhead;
    }
    return dummy->next;
}
```
