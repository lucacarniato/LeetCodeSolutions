#include "../shared/ListNode.hpp"

using namespace std;

class Solution25
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head || k <= 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true)
        {
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = prevGroupEnd;
            for (int i = 0; i < k && groupEnd; ++i)
            {
                groupEnd = groupEnd->next;
            }

            if (!groupEnd)
                break;

            ListNode* nextGroupStart = groupEnd->next;
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;
            while (curr != nextGroupStart)
            {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            prevGroupEnd->next = groupEnd;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};

class Solution25Second
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* cn = head;
        ListNode* chunkHead = head;
        std::vector<ListNode*> revertedListChunks;
        int count = 0;

        while (cn)
        {
            count++;
            if (count % k == 0)
            {

                ListNode* previousNodeChunk = nullptr;
                ListNode* currentNodeChunk = chunkHead;

                int innerCount = 1;

                while (innerCount <= count)
                {
                    const auto nextNodeChunk = currentNodeChunk->next;
                    currentNodeChunk->next = previousNodeChunk;
                    previousNodeChunk = currentNodeChunk;
                    currentNodeChunk = nextNodeChunk;
                    innerCount++;
                }

                revertedListChunks.push_back(previousNodeChunk);

                count = 0;
                chunkHead = currentNodeChunk;
                cn = currentNodeChunk;
            }
            else
            {
                cn = cn->next;
            }
        }

        ListNode* result = nullptr;
        ListNode* cnr = nullptr;

        for (auto& cn : revertedListChunks)
        {
            while (cn)
            {
                if (!result)
                {
                    result = new ListNode(cn->val);
                    cnr = result;
                }
                else
                {
                    cnr->next = new ListNode(cn->val);
                    cnr = cnr->next;
                }
                cn = cn->next;
            }
        }

        cn = chunkHead;
        while (cn)
        {
            if (!result)
            {
                result = new ListNode(cn->val);
                cnr = result;
            }
            else
            {
                cnr->next = new ListNode(cn->val);
                cnr = cnr->next;
            }
            cn = cn->next;
        }

        return result;
    }
};
