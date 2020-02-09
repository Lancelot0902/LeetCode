### 19. Remove Nth Node From End of List

解法1：two pass

```
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == nullptr)
        return head;
    ListNode *begin = new ListNode(0);
    begin->next = head;
    auto it = head;
    int len = 0;
    while (it != nullptr)
    {
        it = it->next;
        len += 1;
    }
    int pos = len - n;
    len = 0;
    it = head;
    auto pre = begin;
    while (len < pos)
    {
        it = it->next;
        pre = pre->next;
        len += 1;
    }
    pre->next = it->next;
    if (it == head)
        return it->next;
    return head;
}
```

时间复杂度：2n

---------------------------------------

解法2：one pass

图解：

![](https://pic.leetcode-cn.com/cc43daa8cbb755373ce4c5cd10c44066dc770a34a6d2913a52f8047cbf5e6e56-file_1559548337458)

```
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    auto p = dummy;
    auto q = dummy;
    for (int i = 0; i < n + 1; ++i)
        q = q->next;
    while (q != nullptr)
    {
        q = q->next;
        p = p->next;
    }
    p->next = p->next->next;
    return dummy->next;
}
```

时间复杂度：n