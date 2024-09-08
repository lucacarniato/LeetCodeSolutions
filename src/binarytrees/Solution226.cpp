using namespace std;
#include "../shared/TreeNode.hpp"

class Solution226
{

    void invert(TreeNode* r)
    {
        if (!r)
        {
            return;
        }

        const auto tmp = r->left;
        r->left = r->right;
        r->right = tmp;
        invert(r->left);
        invert(r->right);
    }

public:
    TreeNode* invertTree(TreeNode* root)
    {
        invert(root);
        return root;
    }
};
