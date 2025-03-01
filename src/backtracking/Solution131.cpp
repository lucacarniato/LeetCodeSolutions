#include <vector>
using namespace std;

class Solution131
{
    bool is_palindrome(const string& s)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    void f(const string& s, vector<string>& partitions, vector<vector<string>>& result, int p)
    {
        if (p == s.size())
        {
            result.push_back(partitions);
            return;
        }

        for (int i = p; i < s.size(); ++i)
        {
            const auto sub_str = s.substr(p, i - p + 1);
            if (is_palindrome(sub_str))
            {
                partitions.push_back(sub_str);
                f(s, partitions, result, i + 1);
                partitions.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> partitions;
        f(s, partitions, result, 0);
        return result;
    }
};
