#include <array>

class Solution567
{
public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        if (s2.size() < s1.size())
        {
            return false;
        }

        const int vocabulary_size = 26;
        std::vector<int> s1_freq(vocabulary_size, 0);
        std::vector<int> s2_freq(vocabulary_size, 0);
        for (int i = 0; i < s1.size(); ++i)
        {
            auto index = s1[i] - 'a';
            s1_freq[index]++;
            index = s2[i] - 'a';
            s2_freq[index]++;
        }

        int num_matches = 0;
        for (int i = 0; i < vocabulary_size; ++i)
        {
            if (s1_freq[i] == s2_freq[i])
            {
                num_matches++;
            }
        }

        if (num_matches == vocabulary_size)
        {
            return true;
        }

        int l = 0;
        for (int r = s1.size(); r < s2.size(); ++r)
        {
            if (num_matches == vocabulary_size)
            {
                return true;
            }

            // right part
            auto index = s2[r] - 'a';
            if (s2_freq[index] == s1_freq[index])
            {
                num_matches--;
            }

            s2_freq[index]++;
            if (s2_freq[index] == s1_freq[index])
            {
                num_matches++;
            }

            // left part
            index = s2[l] - 'a';
            if (s2_freq[index] == s1_freq[index])
            {
                num_matches--;
            }
            s2_freq[index]--;

            if (s2_freq[index] == s1_freq[index])
            {
                num_matches++;
            }

            l++;
        }
        return num_matches == vocabulary_size;
    }
};
