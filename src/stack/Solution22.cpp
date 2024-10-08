#include <string>
#include <unordered_set>
#include <vector>

class Solution22
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> results{"()"};
        for (int i = 2; i <= n; ++i)
        {
            std::unordered_set<std::string> newResults;
            for (const auto& r : results)
            {
                for (int j = 0; j < r.size(); ++j)
                {
                    if (r[j] == '(')
                    {
                        auto first{r};
                        auto second{r};
                        first.insert(j, "()");
                        second.insert(j + 1, "()");
                        newResults.emplace(first);
                        newResults.emplace(second);
                    }
                }
            }
            results.clear();
            results.assign(newResults.begin(), newResults.end());
        }
        return results;
    }
};

class Solution22Second
{

    void backtrack(int no, int nc, int nump, std::string current, std::vector<std::string>& result)
    {
        if (no == nump && nc == nump)
        {
            result.push_back(current);
        }
        if (no > nump)
        {
            return;
        }
        if (nc > nump)
        {
            return;
        }
        if (no < nc)
        {
            return;
        }
        backtrack(no + 1, nc, nump, current + "(", result);
        backtrack(no, nc + 1, nump, current + ")", result);
    }

public:
    std::vector<std::string> generateParenthesis(int n)
    {

        std::string current;
        std::vector<std::string> result;
        backtrack(0, 0, n, current, result);
        return result;
    }
};
