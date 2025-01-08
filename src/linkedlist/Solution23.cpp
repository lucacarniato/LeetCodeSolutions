#include "../shared/ListNode.hpp"

using namespace std;

class Solution23
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        auto cmp = [](ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < lists.size(); ++i)
        {
            if (!lists[i])
            {
                continue;
            }
            pq.emplace(lists[i]);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!pq.empty())
        {
            const auto cn = pq.top();
            pq.pop();

            tail->next = cn;
            tail = tail->next;

            if (cn->next)
            {
                pq.push(cn->next);
            }
        }
        return dummy.next;
    }
};
