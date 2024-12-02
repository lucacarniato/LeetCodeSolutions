using namespace std;
#include "../shared/TreeNode.hpp"
#include <algorithm>

class Solution572
{
    bool isSameTree(TreeNode* s, TreeNode* t)
    {
        if (!s && !t)
        {
            return true;
        }
        if (!s || !t)
        {
            return false;
        }
        return (s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root)
        {
            return false;
        }
        if (isSameTree(root, subRoot))
        {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
