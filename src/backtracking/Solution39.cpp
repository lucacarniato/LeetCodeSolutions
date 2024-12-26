#include <vector>

using namespace std;

// backtracking
class Solution39
{
    void f(vector<int>& candidates,
           vector<vector<int>>& res,
           vector<int>& subset,
           int index,
           int target)
    {
        if (target == 0)
        {
            res.push_back(subset);
            return;
        }
        if (target < 0)
        {
            return;
        }

        for (int i = index; i < candidates.size(); ++i)
        {

            subset.push_back(candidates[i]);
            // repeat the element
            f(candidates, res, subset, i, target - candidates[i]);

            subset.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> subset;
        f(candidates, result, subset, 0, target);
        return result;
    }
};
