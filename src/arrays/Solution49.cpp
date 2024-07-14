#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution49
{
    std::string computeFreq(const string& s)
    {
        vector sf(26, 0);
        for (const auto& v : s)
        {
            const auto ind = v - 'a';
            sf[ind] += 1;
        }

        string result(26 * 2, '00');
        int letter_index = 0;
        for (const auto& v : sf)
        {
            const auto index = letter_index * 2;
            if (v < 10)
            {
                result[letter_index + 1] = static_cast<char>(v);
            }
            else if (v >= 10)
            {
                const auto conv = std::to_string(v);
                result[letter_index] = conv[0];
                result[letter_index + 1] = conv[1];
            }
            letter_index++;
        }
        return result;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> groups;
        for (const auto& s : strs)
        {
            const auto freq = computeFreq(s);
            if (groups.contains(freq))
            {
                groups[freq].push_back(s);
            }
            else
            {
                groups[freq] = vector{s};
            }
        }
        vector<vector<string>> result;
        for (const auto& [k, v] : groups)
        {
            result.push_back(v);
        }
        return result;
    }
};
