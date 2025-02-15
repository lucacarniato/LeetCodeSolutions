using namespace std;
#include "../shared/TreeNode.hpp"
#include <queue>

class Solution199
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        std::vector<int> result;
        if (!root)
        {
            return result;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            const auto size = q.size();
            int val = 0;
            for (int i = 0; i < size; ++i)
            {
                const auto n = q.front();
                val = n->val;
                q.pop();

                if (n->left)
                    q.emplace(n->left);
                if (n->right)
                    q.emplace(n->right);
            }
            result.push_back(val);
        }
        return result;
    }
};
