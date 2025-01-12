#include <array>
#include <queue>
#include <string>

using namespace std;

class Solution76
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
        {
            return "";
        }

        constexpr int vocabulary_size = 256;
        std::array<int, vocabulary_size> tFreq{0};

        int numberOfMatchesToAchive = 0;
        for (int i = 0; i < t.size(); ++i)
        {
            unsigned char pos = t[i];
            tFreq[pos]++;
        }
        for (int i = 0; i < vocabulary_size; ++i)
        {
            if (tFreq[i] > 0)
            {
                numberOfMatchesToAchive++;
            }
        }

        std::queue<size_t> q;
        size_t minSizeOfSubstring = s.size();
        string result = "";
        std::array<int, vocabulary_size> sFreq{0};
        int matchesSoFar = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            unsigned char pos = s[i];
            if (tFreq[pos] == 0)
            {
                continue;
            }

            q.push(i);
            sFreq[pos]++;
            if (sFreq[pos] == tFreq[pos])
            {
                matchesSoFar++;
            }

            if (matchesSoFar == numberOfMatchesToAchive)
            {
                while (sFreq[s[q.front()]] > tFreq[s[q.front()]])
                {
                    sFreq[s[q.front()]]--;
                    q.pop();
                }

                size_t sizeOfSubstring = q.back() - q.front() + 1;
                if (minSizeOfSubstring >= sizeOfSubstring)
                {
                    minSizeOfSubstring = sizeOfSubstring;
                    result = s.substr(q.front(), sizeOfSubstring);
                }
            }
        }
        return result;
    }
};
