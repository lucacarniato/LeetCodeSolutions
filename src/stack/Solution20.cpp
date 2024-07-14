#include <stack>

using namespace std;

class Solution20 {
public:
    bool isValid(string s) 
    {
        std::stack<char> q;
        for(int i=0;i<s.size();++i)
        {
            if( s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                q.push(s[i]);
            }
            else
            {
                if( q.empty() )
                {
                    return false;
                }

                auto p = q.top();
                q.pop();
                if( s[i]==')' && p!='(' )
                {
                    return false;
                }
                if( s[i]==']' && p!='[' )
                {
                    return false;
                }
                if( s[i]=='}' && p!='{' )
                {
                    return false;
                }
            }
        }

        return q.empty();
        
    }
};
