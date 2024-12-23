#include "../shared/TreeNode.hpp"
#include <algorithm>

using namespace std;

class Solution124
{
    int result_;

    int MaxWithoutSplitting(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }

        auto maxLeft = MaxWithoutSplitting(root->left);
        auto maxRight = MaxWithoutSplitting(root->right);

        maxLeft = std::max(maxLeft, 0);
        maxRight = std::max(maxRight, 0);

        result_ = std::max(result_, root->val + maxLeft + maxRight);

        return root->val + std::max(maxLeft, maxRight);
    }

public:
    int maxPathSum(TreeNode* root)
    {
        result_ = -2000;
        MaxWithoutSplitting(root);
        return result_;
    }
};
