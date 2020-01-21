#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    bool carry = false;
    auto it1 = l1;
    auto it2 = l2;
    while (it1 != nullptr && it2 != nullptr)
    {
        if (it1->next == nullptr)
        {
            swap(l1, l2);
            break;
        }
        if (it2->next == nullptr)
            break;
        it1 = it1->next;
        it2 = it2->next;
    }
    it1 = l1;
    it2 = l2;
    auto end = l1;
    while (it1 != nullptr && it2 != nullptr)
    {
        int temp = it1->val + it2->val + carry;
        if (temp >= 10)
        {
            carry = true;
            temp -= 10;
        }
        else
            carry = false;
        it1->val = temp;
        it1 = it1->next;
        it2 = it2->next;
        if (it1->next == nullptr)
            end = it1;
    }
    if (carry)
    {
        if (it1 != nullptr)
        {
            while (it1 != nullptr)
            {
                int temp = it1->val + carry;
                if (temp >= 10)
                {
                    temp -= 10;
                    it1->val = temp;
                }
                else
                {
                    it1->val = temp;
                    carry = false;
                    break;
                }
                if (it1->next == nullptr)
                    end = it1;
            }
            if (carry)
            {
                ListNode *newp = new ListNode(1);
                end->next = newp;
            }
        }
        else
        {
            ListNode *newp = new ListNode(1);
            end->next = newp;
            it1->val = 0;
        }
    }
    return l1;
}