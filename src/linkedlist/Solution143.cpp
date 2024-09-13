#include "../shared/ListNode.hpp"

using namespace std;

class Solution143
{
public:
    void reorderList(ListNode* head)
    {
        if (!head)
        {
            return;
        }

        ListNode* sp = head;
        ListNode* fp = head;
        while (fp && fp->next)
        {
            sp = sp->next;
            fp = fp->next->next;
        }

        // Second list
        ListNode* sl = sp->next;
        // First list
        sp->next = nullptr;

        ListNode* pn = nullptr;
        while (sl)
        {
            const auto nn = sl->next;
            sl->next = pn;
            pn = sl;
            sl = nn;
        }

        ListNode* fl = head;
        sl = pn;
        while (sl)
        {
            const auto fln = fl->next;
            const auto sln = sl->next;
            fl->next = sl;
            sl->next = fln;
            fl = fln;
            sl = sln;
        }
    }
};
