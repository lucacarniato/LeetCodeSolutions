using namespace std;
#include "../shared/TreeNode.hpp"

class Solution226
{
    void invert(TreeNode* root)
    {
        if (!root)
        {
            return;
        }

        auto l = root->left;
        auto r = root->right;
        root->left = r;
        root->right = l;

        invert(root->left);
        invert(root->right);
    }

public:
    TreeNode* invertTree(TreeNode* root)
    {
        invert(root);
        return root;
    }
};
