#include "../shared/ListNode.hpp"

using namespace std;

class Solution206
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head)
        {
            return head;
        }

        ListNode* pn = nullptr;
        ListNode* nn = nullptr;
        ListNode* cn = head;
        while (cn)
        {
            nn = cn->next;
            cn->next = pn;
            pn = cn;
            cn = nn;
        }

        return pn;
    }
};
