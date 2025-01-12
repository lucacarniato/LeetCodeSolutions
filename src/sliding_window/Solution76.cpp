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
        std::array<int, vocabulary_size> freqMap{0};

        int charToMatch = 0;
        for (int i = 0; i < t.size(); ++i)
        {
            unsigned char pos = t[i];
            freqMap[pos]++;
        }
        for (int i = 0; i < vocabulary_size; ++i)
        {
            if (freqMap[i] > 0)
            {
                charToMatch++;
            }
        }

        std::queue<size_t> q;
        size_t minSizeOfSubstring = s.size();
        string result = "";
        std::array<int, vocabulary_size> freqSubstr{0};
        int matched = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            unsigned char pos = s[i];
            if (freqMap[pos] == 0)
            {
                continue;
            }

            freqSubstr[pos]++;
            if (freqSubstr[pos] == freqMap[pos])
            {
                matched++;
            }
            q.push(i);

            // matching found, evaluate min string
            if (matched == charToMatch)
            {
                while (freqSubstr[s[q.front()]] > freqMap[s[q.front()]])
                {
                    freqSubstr[s[q.front()]]--;
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
