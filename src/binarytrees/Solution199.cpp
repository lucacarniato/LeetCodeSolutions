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
            result.push_back(q.back()->val);
            for (int i = 0; i < size; ++i)
            {
                const auto n = q.front();
                q.pop();

                if (n->left)
                    q.emplace(n->left);
                if (n->right)
                    q.emplace(n->right);
            }
        }
        return result;
    }
};
