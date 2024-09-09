#include "../shared/ListNode.hpp"

using namespace std;

class Solution141
{
public:
    bool hasCycle(ListNode* head)
    {
        if (!head)
        {
            return head;
        }

        unordered_set<ListNode*> nodeVisted;
        ListNode* cn = head;
        while (cn)
        {
            if (nodeVisted.contains(cn))
            {
                return true;
            }
            nodeVisted.insert(cn);
            cn = cn->next;
        }
        return false;
    }
};

class Solution141Second
{
public:
    bool hasCycle(ListNode* head)
    {
        if (!head)
        {
            return head;
        }

        ListNode* sp = head;
        ListNode* fp = head;
        while (fp && fp->next)
        {
            sp = sp->next;
            fp = fp->next->next;
            if (sp == fp)
            {
                return true;
            }
        }
        return false;
    }
};
