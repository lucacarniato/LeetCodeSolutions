#include "binarytrees/Solution102.cpp"
#include "shared/ListNode.hpp"
#include "shared/TreeNode.hpp"

int main()
{
    auto* r0 = new TreeNode(3);
    auto* r1 = new TreeNode(9);
    auto* r2 = new TreeNode(20);
    auto* r3 = new TreeNode(15);
    auto* r4 = new TreeNode(7);

    r0->left = r1;
    r0->right = r2;

    r2->left = r3;
    r2->right = r4;

    Solution102 solution;
    auto result = solution.levelOrder(r0);

    return 0;
}
