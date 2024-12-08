using namespace std;
#include "../shared/TreeNode.hpp"
#include <algorithm>

class Solution230
{
    void Extract(TreeNode* root, int k, int& currentK, int& result)
    {
        if (!root)
        {
            return;
        }

        Extract(root->left, k, currentK, result);

        currentK = currentK + 1;
        if (currentK == k)
        {
            result = root->val;
            return;
        }
        Extract(root->right, k, currentK, result);
    }

public:
    int kthSmallest(TreeNode* root, int k)
    {
        int result = -1;
        int currentK = 0;
        Extract(root, k, currentK, result);
        return result;
    }
};
