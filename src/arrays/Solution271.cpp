#include <string>
#include <vector>

using namespace std;

class Solution271
{
public:
    string encode(vector<string>& strs)
    {
        string result;
        for (const auto& s : strs)
        {
            result += std::to_string(s.size()) + "#" + s;
        }
        return result;
    }

    vector<string> decode(string s)
    {
        vector<string> result;
        int pos = 0;
        while (pos < s.size())
        {
            string sizestr;
            while (s[pos] != '#')
            {
                sizestr += s[pos];
                pos++;
            }
            pos = pos + 1;
            int size = std::stoi(sizestr);
            result.push_back(s.substr(pos, size));
            pos += size;
        }

        return result;
    }
};
