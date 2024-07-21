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
