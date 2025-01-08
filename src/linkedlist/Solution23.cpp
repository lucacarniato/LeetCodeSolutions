#include "../shared/ListNode.hpp"

using namespace std;

class Solution23
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* result = nullptr;
        ListNode* cnResult = nullptr;

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

        while (!pq.empty())
        {
            const auto cn = pq.top();
            const auto val = cn->val;
            const auto cnn = cn->next;
            pq.pop();

            if (cnn)
            {
                pq.push(cnn);
            }

            if (result == nullptr)
            {
                result = new ListNode(val);
                cnResult = result;
            }
            else
            {
                cnResult->next = new ListNode(val);
                cnResult = cnResult->next;
            }
        }
        return result;
    }
};
