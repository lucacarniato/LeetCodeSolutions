using namespace std;
#include "../shared/TreeNode.hpp"
#include <algorithm>

class Solution543
{

    int maxDiameter = 0;

    int ComputeDiameter(TreeNode* r)
    {
        if (!r)
        {
            return 0;
        }
        const int left = ComputeDiameter(r->left);
        const int right = ComputeDiameter(r->right);
        maxDiameter = max(maxDiameter, left + right);
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* r)
    {
        ComputeDiameter(r);

        return maxDiameter;
    };
};
