#include "binarytrees/Solution543.cpp"

int main()
{
    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);

    r->left->left = new TreeNode(4);
    r->left->right = new TreeNode(5);

    Solution543 solution;
    int result = solution.diameterOfBinaryTree(r);

    return 0;
}
