#include "binarytrees/Solution105.cpp"
#include "shared/TreeNode.hpp"
#include <vector>

int main()
{
    auto* r0 = new TreeNode(1);
    auto* r1 = new TreeNode(2);
    auto* r2 = new TreeNode(3);

    r0->left = r1;
    r1->right = r2;

    Solution105 solution;
    std::vector<int> preorder{3, 9, 20, 15, 7};
    std::vector<int> inorder{9, 3, 15, 20, 7};

    auto result = solution.buildTree(preorder, inorder);

    return 0;
}
