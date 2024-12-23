#include "../shared/TreeNode.hpp"
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution105
{
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int spr, int epr, int sin, int ein)
    {
        if (spr > epr || sin > ein)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[spr]);

        auto it = std::find(inorder.begin() + sin, inorder.begin() + ein + 1, preorder[spr]);
        if (it == inorder.end())
            return nullptr;

        int inorderIndex = std::distance(inorder.begin(), it);
        int numLeft = inorderIndex - sin;

        root->left = build(preorder,
                           inorder,
                           spr + 1,
                           spr + numLeft,
                           sin,
                           inorderIndex - 1);

        root->right = build(preorder,
                            inorder,
                            spr + numLeft + 1,
                            epr,
                            inorderIndex + 1,
                            ein);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int epr = preorder.size() - 1;
        int ein = inorder.size() - 1;

        return build(preorder, inorder, 0, epr, 0, ein);
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
