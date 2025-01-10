#include <array>

class Solution567
{
public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }

        constexpr int vocabulary_size = 26;
        std::array<int, vocabulary_size> s1f, s2f;

        for (size_t i = 0; i < s1.size(); ++i)
        {
            size_t pos = s1[i] - 'a';
            s1f[pos] += 1;
            pos = s2[i] - 'a';
            s2f[pos] += 1;
        }

        // Count matches
        int matches = 0;
        for (int i = 0; i < vocabulary_size; ++i)
        {
            if (s1f[i] == s2f[i])
            {
                matches++;
            }
        }

        // Slide the window over s2
        int l = 0;
        for (size_t r = s1.size(); r < s2.size(); ++r)
        {
            if (matches == vocabulary_size)
                return true;

            // Add the new character to the window
            int rightChar = s2[r] - 'a';
            s2f[rightChar]++;
            if (s2f[rightChar] == s1f[rightChar])
            {
                matches++;
            }
            else if (s2f[rightChar] == s1f[rightChar] + 1)
            {
                matches--;
            }

            // Remove the leftmost character from the window
            int leftChar = s2[l] - 'a';
            s2f[leftChar]--;
            if (s2f[leftChar] == s1f[leftChar])
            {
                matches++;
            }
            else if (s2f[leftChar] == s1f[leftChar] - 1)
            {
                matches--;
            }
            l++;
        }

        return matches == vocabulary_size;
    }
};
