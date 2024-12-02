using namespace std;
#include "../shared/TreeNode.hpp"
#include <algorithm>

class Solution235
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root)
        {
            return root;
        }

        int minVal = std::min(p->val, q->val);
        int maxVal = std::max(p->val, q->val);

        if (root->val >= minVal && root->val <= maxVal)
        {
            return root;
        }
        if (root->val < minVal)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return lowestCommonAncestor(root->left, p, q);
    }
};
