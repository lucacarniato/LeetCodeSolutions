using namespace std;
#include "../shared/TreeNode.hpp"

class Solution104
{
    int maxDepthRecursive(TreeNode* r)
    {
        if (!r)
        {
            return 0;
        }
        return 1 + std::max(maxDepthRecursive(r->left), maxDepthRecursive(r->right));
    }

public:
    int maxDepth(TreeNode* root)
    {
        return maxDepthRecursive(root);
    }
};
