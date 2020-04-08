### 876. Middle of the Linked List

两次遍历

```
ListNode *middleNode(ListNode *head)
{
    int len = 0;
    for (auto it = head; it != nullptr; it = it->next)
        len += 1;
    auto it = head;
    for (int i = 0; i < len / 2; ++i)
        it = it->next;
    return it;
}
```
