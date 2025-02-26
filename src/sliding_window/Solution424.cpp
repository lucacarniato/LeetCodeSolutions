#include <vector>
using namespace std;

class Solution424
{
public:
    int characterReplacement(std::string s, int k)
    {
        int maxLength = 0;
        int maxCount = 0;
        int start = 0;
        vector<int> count(26, 0);

        for (int end = 0; end < s.length(); ++end)
        {
            count[s[end] - 'A']++;
            maxCount = max(maxCount, count[s[end] - 'A']);

            while ((end - start + 1) - maxCount > k)
            {
                count[s[start] - 'A']--;
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
