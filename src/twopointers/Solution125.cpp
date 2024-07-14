#include <locale>

using namespace std;

class Solution125
{
public:
    bool isPalindrome(string s)
    {
        int lind = 0;
        int rind = s.size() - 1;
        while (lind < rind)
        {
            while (lind < s.size() && (!std::isalnum(s[lind])))
            {
                lind++;
            }
            while (rind > 0 && (!std::isalnum(s[rind])))
            {
                rind--;
            }
            if (lind >= s.size() || rind < 0)
            {
                break;
            }
            if (std::tolower(s[lind]) != std::tolower(s[rind]))
            {
                return false;
            }
            lind++;
            rind--;
        }
        return true;
    }
};