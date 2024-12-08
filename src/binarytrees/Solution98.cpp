using namespace std;
#include "../shared/TreeNode.hpp"
#include <algorithm>

class Solution98
{
    bool isValid(TreeNode* root, long long minVal, long long maxVal)
    {
        if (!root)
        {
            return true;
        }
        // Check if the current node violates the BST property
        if (root->val <= minVal || root->val >= maxVal)
        {
            return false;
        }
        // Recur for left and right subtrees with updated ranges
        return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root)
    {
        // Use long long to handle edge cases with extreme integer values
        return isValid(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    }
};