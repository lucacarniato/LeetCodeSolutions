#include "binarytrees/Solution98.cpp"
#include "shared/TreeNode.hpp"

int main()
{
    auto* r0 = new TreeNode(2);
    auto* r1 = new TreeNode(1);
    auto* r2 = new TreeNode(3);

    r0->left = r1;
    r0->right = r2;

    Solution98 solution;
    auto result = solution.isValidBST(r0);

    return 0;
}
