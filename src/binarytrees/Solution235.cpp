using namespace std;
#include "../shared/TreeNode.hpp"
#include <algorithm>

class Solution235
{
    TreeNode* findLCA(TreeNode* root, const int& minVal, const int& maxVal)
    {
        if (!root)
        {
            return root;
        }

        if (root->val >= minVal && root->val <= maxVal)
        {
            return root;
        }
        if (root->val < minVal)
        {
            return findLCA(root->right, minVal, maxVal);
        }
        return findLCA(root->left, minVal, maxVal);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        int minVal = std::min(p->val, q->val);
        int maxVal = std::max(p->val, q->val);
        return findLCA(root, minVal, maxVal);
    }
};
