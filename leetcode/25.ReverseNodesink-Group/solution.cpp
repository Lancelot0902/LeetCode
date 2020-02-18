#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
