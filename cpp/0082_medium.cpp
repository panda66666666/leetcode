#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline void deleteNode(ListNode *node)
{
    ListNode *tem = node->next;
    node->next = node->next->next;
    delete tem;
}

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *pre_node = new ListNode(0, head);
        ListNode *res = pre_node;

        while (head)
        {
            bool flag = (head->next && head->val == head->next->val);
            while (head->next && head->val == head->next->val)
                deleteNode(head);

            head = head->next;

            if (flag)
                deleteNode(pre_node);
            pre_node = flag ? pre_node : pre_node->next;
        }

        return res->next;
    }
};