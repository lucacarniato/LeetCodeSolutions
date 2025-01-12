#include <array>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution76
{
public:
    string minWindow(string s, string t)
    {
        if (t.empty() || s.empty() || s.size() < t.size())
        {
            return "";
        }

        std::unordered_map<char, int> tFreq;
        for (int i = 0; i < t.size(); ++i)
        {
            tFreq[t[i]]++;
        }
        const auto numberOfMatchesToAchive = tFreq.size();

        std::unordered_map<char, int> sFreq;
        size_t l = 0;
        size_t matchesSoFar = 0;
        size_t maxStringSize = static_cast<size_t>(1e6);
        size_t currentMinStringSize = maxStringSize;
        size_t pos = 0;

        for (int i = 0; i < s.size(); ++i)
        {

            sFreq[s[i]]++;
            if (tFreq.contains(s[i]) && sFreq[s[i]] == tFreq[s[i]])
            {
                matchesSoFar++;
            }

            while (matchesSoFar == numberOfMatchesToAchive)
            {
                size_t currentSubStringLength = i - l + 1;
                if (currentSubStringLength < currentMinStringSize)
                {
                    currentMinStringSize = currentSubStringLength;
                    pos = l;
                }

                sFreq[s[l]]--;
                if (tFreq.contains(s[l]) && sFreq[s[l]] < tFreq[s[l]])
                {
                    matchesSoFar--;
                }
                l++;
            }
        }

        return currentMinStringSize == maxStringSize ? "" : s.substr(pos, currentMinStringSize);
    }
};

class Solution76Second
{
public:
    string minWindow(string s, string t)
    {
        if (t.empty() || s.empty() || s.size() < t.size())
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
                while (!q.empty() && sFreq[s[q.front()]] > tFreq[s[q.front()]])
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
