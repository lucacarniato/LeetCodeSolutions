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
            return result;

        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty())
        {
            int numNodes = nodeQueue.size();
            vector<int> level;

            for (int i = 0; i < numNodes; ++i)
            {
                auto currentNode = nodeQueue.front();
                nodeQueue.pop();
                level.push_back(currentNode->val);

                if (currentNode->left)
                    nodeQueue.push(currentNode->left);
                if (currentNode->right)
                    nodeQueue.push(currentNode->right);
            }
            result.push_back(level);
        }
        return result;
    }
};
