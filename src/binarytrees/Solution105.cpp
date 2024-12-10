#include <ios>
using namespace std;
#include "../shared/TreeNode.hpp"
#include <algorithm>
#include <unordered_map>

class Solution105
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
