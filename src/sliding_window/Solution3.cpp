#include <unordered_set>

class Solution3Second
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_set<int> unique_chars;
        int l = 0;
        int result = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            while (unique_chars.contains(s[i]))
            {
                unique_chars.erase(s[l]);
                l++;
            }
            unique_chars.insert(s[i]);
            result = std::max(result, i - l + 1);
        }
        return result;
    }
};

class Solution3
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        if (s.empty())
        {
            return 0;
        }

        std::vector<int> position(128, -1);
        std::queue<char> substr;
        int result = 0;
        int first = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (position[s[i]] != -1)
            {
                while (!substr.empty() && substr.front() != s[i])
                {
                    position[substr.front()] = -1;
                    substr.pop();
                }
                if (!substr.empty())
                {
                    position[substr.front()] = -1;
                    substr.pop();
                }
            }
            position[s[i]] = i;
            substr.push(s[i]);
            result = std::max(result, int(substr.size()) - first);
        }

        return result;
    }
};
