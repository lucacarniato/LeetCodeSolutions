using namespace std;
#include "../shared/TreeNode.hpp"
#include <algorithm>

class Solution110
{
    bool isBalancedTree = true;

    int ComputeHeight(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        if (!isBalancedTree)
        {
            return 0;
        }

        int leftHeight = ComputeHeight(root->left);
        int rightHeight = ComputeHeight(root->right);
        isBalancedTree = isBalancedTree && std::abs(rightHeight - leftHeight) <= 1;

        return 1 + std::max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root)
    {
        ComputeHeight(root);
        return isBalancedTree;
    }
};
