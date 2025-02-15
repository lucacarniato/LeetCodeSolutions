using namespace std;
#include "../shared/TreeNode.hpp"
#include <algorithm>

class Solution230
{
    int results_;
    int counter_ = 0;

    void traverse(TreeNode* r, int k)
    {
        if (!r)
        {
            return;
        }
        if (counter_ >= k)
        {
            return;
        }

        traverse(r->left, k);
        if (counter_ + 1 == k)
        {
            results_ = r->val;
        }
        counter_++;
        traverse(r->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k)
    {
        traverse(root, k);
        return results_;
    }
};
