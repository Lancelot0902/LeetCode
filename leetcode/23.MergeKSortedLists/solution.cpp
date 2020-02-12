#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    auto pre = dummy;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2->val)
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
    if (l1 != nullptr)
        pre->next = l1;
    else
        pre->next = l2;
    return dummy->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    for (int i = 1; i != lists.size(); ++i)
    {
        lists[0] = merge(lists[0], lists[i]);
    }
    return lists[0];
}
