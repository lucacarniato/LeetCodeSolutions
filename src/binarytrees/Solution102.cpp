using namespace std;
#include "../shared/TreeNode.hpp"
#include <queue>
#include <vector>

class Solution102
{
    vector<vector<int>> valuesAtLevels_;

    void InOrderTraversal(TreeNode* root, int level)
    {
        if (!root)
        {
            return;
        }

        if (valuesAtLevels_.size() <= level)
        {
            valuesAtLevels_.push_back(vector<int>());
        }

        InOrderTraversal(root->left, level + 1);

        valuesAtLevels_[level].push_back(root->val);

        InOrderTraversal(root->right, level + 1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        InOrderTraversal(root, 0);
        return valuesAtLevels_;
    }
};

class Solution102Second
{

public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if (!root)
        {
            return result;
        }

        std::queue<std::tuple<int, TreeNode*>> q;
        q.emplace(0, root);

        while (!q.empty())
        {
            const auto [level, n] = q.front();
            q.pop();

            if (result.size() <= level)
            {
                result.emplace_back();
            }

            result[level].push_back(n->val);

            if (n->left)
            {
                q.emplace(level + 1, n->left);
            }
            if (n->right)
            {
                q.emplace(level + 1, n->right);
            }
        }
        return result;
    }
};
