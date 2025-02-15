#include "../shared/TreeNode.hpp"
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution105
{
    std::unordered_map<int, int> inorder_maps_;

    TreeNode* f(
        const vector<int>& preorder,
        const vector<int>& inorder,
        int preorder_index,
        int inorder_start,
        int inorder_end,
        int postorder_start,
        int postorder_end)
    {
        if (inorder_start > inorder_end || postorder_start > postorder_end)
        {
            return nullptr;
        }

        if (preorder_index >= preorder.size())
        {
            return nullptr;
        }

        const auto v = preorder[preorder_index];
        TreeNode* result = new TreeNode(v);
        const auto node_index = inorder_maps_[v];
        int left_tree_size = node_index - inorder_start;

        result->left = f(
            preorder,
            inorder,
            preorder_index + 1,
            inorder_start,
            node_index - 1,
            preorder_index + 1,
            preorder_index + left_tree_size);

        result->right = f(
            preorder,
            inorder,
            preorder_index + 1 + left_tree_size,
            node_index + 1,
            inorder_end,
            preorder_index + left_tree_size + 1,
            postorder_end);

        return result;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            const auto v = inorder[i];
            inorder_maps_[v] = i;
        }
        return f(preorder, inorder, 0, 0, preorder.size(), 0, preorder.size());
    }
};

class Solution105Second
{
    std::unordered_map<int, int> inordermap_;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.empty() || inorder.empty())
        {
            return nullptr;
        }

        for (int i = 0; i < inorder.size(); ++i)
        {
            inordermap_[inorder[i]] = i;
        }

        std::vector<TreeNode*> preorderNodes(inorder.size(), nullptr);
        std::vector<TreeNode*> inorderNodes(inorder.size(), nullptr);

        preorderNodes[0] = new TreeNode(preorder[0]);
        inorderNodes[inordermap_[preorder[0]]] = preorderNodes[0];

        TreeNode* result = preorderNodes[0];
        for (int i = 1; i < preorder.size(); ++i)
        {
            preorderNodes[i] = new TreeNode(preorder[i]);
            inorderNodes[inordermap_[preorder[i]]] = preorderNodes[i];
            if (inordermap_[preorder[i]] < inordermap_[preorder[i - 1]])
            {
                preorderNodes[i - 1]->left = preorderNodes[i];
            }
            else
            {
                auto currentIndex = inordermap_[preorder[i]] - 1;
                while (currentIndex >= 0)
                {
                    if (inorderNodes[currentIndex])
                    {
                        inorderNodes[currentIndex]->right = preorderNodes[i];
                        break;
                    }
                    currentIndex--;
                }
            }
        }
        return result;
    }
};
