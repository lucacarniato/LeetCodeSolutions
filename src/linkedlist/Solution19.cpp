#include "../shared/ListNode.hpp"

using namespace std;

class Solution19
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
