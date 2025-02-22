#include "../shared/ListNode.hpp"

using namespace std;

class Solution19
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; ++i)
        {
            first = first->next;
        }

        while (first)
        {
            first = first->next;
            second = second->next;
        }

        ListNode* node_to_delete = second->next;
        second->next = second->next->next;
        delete node_to_delete;

        head = dummy->next;
        delete dummy;
        return head;
    }
};

class Solution19Second
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (!head)
        {
            return nullptr;
        }

        int count = 0;
        ListNode* cn = head;
        while (cn)
        {
            cn = cn->next;
            count += 1;
        }

        int target = count - n;
        count = 0;
        cn = head;
        ListNode* pn = nullptr;
        while (cn)
        {
            if (count == target)
            {
                if (cn == head)
                {
                    head = cn->next;
                    delete cn;
                    break;
                }
                pn->next = cn->next;
                delete cn;
                break;
            }
            pn = cn;
            cn = cn->next;
            count += 1;
        }
        return head;
    }
};
