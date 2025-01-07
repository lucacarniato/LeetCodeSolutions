/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "../shared/TreeNode.hpp"

#include <queue>
#include <sstream>
#include <string>
#include <vector>

struct TreeNode;
using namespace std;

class Solution297
{
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root)
    {
        if (!root)
        {
            return "[]";
        }

        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        std::string result = "[";

        while (!nodeQueue.empty())
        {
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();

            if (currentNode)
            {
                result += std::to_string(currentNode->val) + ",";
                nodeQueue.push(currentNode->left);
                nodeQueue.push(currentNode->right);
            }
            else
            {
                result += "null,";
            }
        }

        if (!result.empty() && result.back() == ',')
        {
            result.back() = ']';
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const std::string& data)
    {
        if (data.size() <= 2 || data.front() != '[' || data.back() != ']')
        {
            return nullptr;
        }

        std::string cleanedData = data.substr(1, data.size() - 2); // Remove brackets
        std::vector<std::string> values = tokenize(cleanedData, ',');

        if (values.empty() || values[0] == "null")
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(std::stoi(values[0]));
        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        size_t index = 1;
        while (!nodeQueue.empty() && index < values.size())
        {
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();

            if (index < values.size() && values[index] != "null")
            {
                currentNode->left = new TreeNode(std::stoi(values[index]));
                nodeQueue.push(currentNode->left);
            }
            index++;

            if (index < values.size() && values[index] != "null")
            {
                currentNode->right = new TreeNode(std::stoi(values[index]));
                nodeQueue.push(currentNode->right);
            }
            index++;
        }

        return root;
    }

private:
    std::vector<std::string> tokenize(const std::string& str, char delimiter)
    {
        std::vector<std::string> tokens;
        std::stringstream sstream(str);
        std::string token;

        while (std::getline(sstream, token, delimiter))
        {
            tokens.push_back(token);
        }

        return tokens;
    }
};
