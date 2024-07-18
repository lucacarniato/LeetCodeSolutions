#include "../shared/TreeNode.hpp"
#include <unordered_map>

using namespace std;

class Solution337
{

    int f(TreeNode* n, unordered_map<TreeNode*, int>& t)
    {
        if (n == nullptr)
        {
            return 0;
        }
        if (t.find(n) != t.end())
        {
            return t[n];
        }

        auto left = f(n->left, t);
        auto right = f(n->right, t);
        auto ans = n->val;

        if (n->left != nullptr)
        {
            ans += f(n->left->left, t);
            ans += f(n->left->right, t);
        }
        if (n->right != nullptr)
        {
            ans += f(n->right->left, t);
            ans += f(n->right->right, t);
        }

        const auto res = max(ans, left + right);

        t[n] = res;

        return res;
    }

public:
    int rob(TreeNode* root)
    {
        unordered_map<TreeNode*, int> t;
        auto const res = f(root, t);
        return res;
    }
};
