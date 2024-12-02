using namespace std;
#include "../shared/TreeNode.hpp"
#include <algorithm>

class Solution110
{

    bool isBalanced = true;

    int IsBalanced(TreeNode* r)
    {
        if (!r)
        {
            return 0;
        }
        const int left = IsBalanced(r->left);
        const int right = IsBalanced(r->right);
        const int absDiff = std::abs(left - right);
        if (absDiff > 1)
        {
            isBalanced = false;
            return 0;
        }
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* r)
    {
        IsBalanced(r);
        return isBalanced;
    };
};
