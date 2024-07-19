#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution150
{
public:
    int evalRPN(vector<string>& tokens)
    {
        std::stack<int> s;
        std::set<string> op{"+", "-", "*", "/"};
        int result = 0;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (op.contains(tokens[i]))
            {

                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();

                if (tokens[i] == "+")
                {
                    result = left + right;
                }
                else if (tokens[i] == "-")
                {
                    result = left - right;
                }
                else if (tokens[i] == "*")
                {
                    result = left * right;
                }
                else if (tokens[i] == "/")
                {
                    result = left / right;
                }
                s.push(result);
            }
            else
            {
                s.push(std::stoi(tokens[i]));
            }
        }

        result = s.top();

        return result;
    }
};
