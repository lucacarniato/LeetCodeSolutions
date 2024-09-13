#include "linkedlist/Solution143.cpp"
#include "shared/ListNode.hpp"

int main()
{
    ListNode* r0 = new ListNode(1);
    ListNode* r1 = new ListNode(2);
    ListNode* r2 = new ListNode(3);
    ListNode* r3 = new ListNode(4);
    ListNode* r4 = new ListNode(5);

    r0->next = r1;
    r1->next = r2;
    r2->next = r3;
    r3->next = r4;

    Solution143 solution;
    solution.reorderList(r0);

    return 0;
}
