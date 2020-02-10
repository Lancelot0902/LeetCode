#include <iostream>
#include <algorithm>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    std::vector<int> vec;
    auto it = l1;
    while (it->next != nullptr)
    {
        vec.push_back(it->val);
        it = it->next;
    }
    it->next = l2;
    while (it != nullptr)
    {
        vec.push_back(it->val);
        it = it->next;
    }
    std::sort(vec.begin(), vec.end());
    it = l1;
    for (int i = 0; i != vec.size(); ++i)
    {
        it->val = vec[i];
        it = it->next;
    }
    return l1;
}
