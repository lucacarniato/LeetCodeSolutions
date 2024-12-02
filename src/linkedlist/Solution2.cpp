#include "../shared/ListNode.hpp"

using namespace std;

class Solution2
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;
        int carry = 0;

        // Traverse both lists
        while (l1 || l2 || carry)
        {
            int sum = carry;

            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummyHead->next;
    }
};
