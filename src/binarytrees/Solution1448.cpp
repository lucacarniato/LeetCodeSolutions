using namespace std;
#include "../shared/TreeNode.hpp"
#include <algorithm>

class Solution1448
{

    void traverse(TreeNode* r, int rootval, int pval, int& num)
    {
        if (!r)
        {
            return;
        }

        int newpval = std::max(pval, r->val);
        traverse(r->left, rootval, newpval, num);
        if (r->val >= rootval && r->val >= pval)
        {
            num = num + 1;
        }
        traverse(r->right, rootval, newpval, num);
    }

public:
    int goodNodes(TreeNode* root)
    {
        int num = 0;
        if (!root)
        {
            return num;
        }
        traverse(root, root->val, -10e5, num);
        return num;
    }
};
