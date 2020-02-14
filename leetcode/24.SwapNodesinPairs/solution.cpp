#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    auto pre = dummy;
    auto cur = head;
    auto bck = head->next;
    while (bck != nullptr)
    {
        pre->next = bck;
        cur->next = bck->next;
        bck->next = cur;

        pre = cur;
        cur = cur->next;
        bck = cur->next;
    }
    return dummy->next;
}
