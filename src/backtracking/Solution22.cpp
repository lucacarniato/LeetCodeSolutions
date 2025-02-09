#include <string>
#include <vector>

using namespace std;

class Solution22
{
    void backtrack(vector<string>& result, std::string& val, int nc, int no, int n)
    {
        if (nc == n && no == n)
        {
            result.push_back(val);
            return;
        }
        if (no < nc)
        {
            return;
        }

        if (no < n)
        {
            val += '(';
            backtrack(result, val, nc, no + 1, n);
            val.pop_back();
        }

        val += ')';
        backtrack(result, val, nc + 1, no, n);
        val.pop_back();
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        std::string val{"("};
        backtrack(result, val, 0, 1, n);
        return result;
    }
};
