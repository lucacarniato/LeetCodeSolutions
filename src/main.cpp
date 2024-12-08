#include "binarytrees/Solution230.cpp"
#include "shared/TreeNode.hpp"

int main()
{
    auto* r0 = new TreeNode(5);
    auto* r1 = new TreeNode(3);
    auto* r2 = new TreeNode(6);
    auto* r3 = new TreeNode(4);
    auto* r4 = new TreeNode(2);
    auto* r5 = new TreeNode(1);

    r0->left = r1;
    r0->right = r2;
    r1->right = r3;
    r1->left = r4;
    r4->left = r5;

    Solution230 solution;
    auto result = solution.kthSmallest(r0, 3);

    return 0;
}
