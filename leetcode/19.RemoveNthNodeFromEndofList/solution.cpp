#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
