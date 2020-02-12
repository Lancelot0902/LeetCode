### 23. Merge K Sorted Lists

一个接一个的合并列表

```
ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    auto pre = dummy;
    while (l1 != nullptr && l2 != nullptr)
    {
        if(l1->val <= l2->val)
        {
            pre->next = l1;
            l1 = l1->next;
        }
        else
        {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    if(l1 != nullptr)
        pre->next = l1;
    else
        pre->next = l2;
    return dummy->next;
}
```
