using namespace std;
#include "../shared/TreeNode.hpp"
#include <algorithm>

class Solution1448
{
    void traverse(TreeNode* root, int rootVal, int& counter)
    {
        if (!root)
        {
            return;
        }

        if (root->val >= rootVal)
        {
            counter++;
        }
        if (root->left)
        {
            traverse(root->left, std::max(rootVal, root->left->val), counter);
        }
        if (root->right)
        {
            traverse(root->right, std::max(rootVal, root->right->val), counter);
        }
    }

public:
    int goodNodes(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        int counter = 0;
        traverse(root, root->val, counter);
        return counter;
    }
};
