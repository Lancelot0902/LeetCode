#include <iosteam>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
