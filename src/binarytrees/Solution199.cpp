using namespace std;
#include "../shared/TreeNode.hpp"
#include <queue>

class Solution199
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> result;
        if (!root)
        {
            return result;
        }

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            const auto size = q.size();

            int val;
            for (int i = 0; i < size; ++i)
            {
                const auto v = q.front();
                q.pop();

                val = v->val;
                if (v->left)
                {
                    q.push(v->left);
                }
                if (v->right)
                {
                    q.push(v->right);
                }
            }
            result.push_back(val);
        }

        return result;
    }
};
