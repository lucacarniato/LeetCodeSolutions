#include "../shared/ListNode.hpp"

using namespace std;

class Solution21
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {

        auto cn1 = list1;
        auto cn2 = list2;
        ListNode* result = nullptr;
        ListNode* next = nullptr;
        while (cn1 != nullptr || cn2 != nullptr)
        {
            ListNode* next_node = nullptr;
            if (cn1 == nullptr)
            {
                next_node = new ListNode(cn2->val);
                cn2 = cn2->next;
            }
            else if (cn2 == nullptr)
            {
                next_node = new ListNode(cn1->val);
                cn1 = cn1->next;
            }
            else if (cn1->val <= cn2->val)
            {
                next_node = new ListNode(cn1->val);
                cn1 = cn1->next;
            }
            else
            {
                next_node = new ListNode(cn2->val);
                cn2 = cn2->next;
            }

            if (result == nullptr)
            {
                result = next_node;
                next = next_node;
            }
            else
            {
                next->next = next_node;
                next = next_node;
            }
        }
        return result;
    }
};
