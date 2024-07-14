#include "../shared/ListNode.hpp"

using namespace std;

class Solution2
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {

        ListNode* head = new ListNode();
        auto ch = head;
        auto cn1 = l1;
        auto cn2 = l2;
        int rem = 0;

        while (cn1 != nullptr || cn2 != nullptr)
        {
            int l1val = 0;
            int l2val = 0;
            if (cn1 != nullptr)
            {
                l1val = cn1->val;
                cn1 = cn1->next;
            }
            if (cn2 != nullptr)
            {
                l2val = cn2->val;
                cn2 = cn2->next;
            }

            int sum = l1val + l2val + rem;
            int val = sum % 10;
            rem = int(sum / 10);
            ch->val = val;

            if (cn1 != nullptr || cn2 != nullptr)
            {
                ch->next = new ListNode();
                ch = ch->next;
            }
        }
        if (rem != 0)
        {
            ch->next = new ListNode();
            ch->next->val = rem;
        }

        return head;
    }
};
