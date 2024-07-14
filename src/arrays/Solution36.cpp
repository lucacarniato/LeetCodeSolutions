#include <unordered_set>
#include <vector>

using namespace std;

class Solution36
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        // loop over the  cells
        vector cells(3, vector(3, std::unordered_set<int>()));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                int r = static_cast<int>(i / 3);
                int c = static_cast<int>(j / 3);
                const int valchar = board[i][j];
                if (valchar == '.')
                {
                    continue;
                }
                const int val = static_cast<int>(valchar - '0');
                if (val < 1 || val > 9)
                {
                    return false;
                }
                if (cells[r][c].contains(val))
                {
                    return false;
                }
                cells[r][c].insert(val);
            }
        }

        // loop over the rows
        for (int i = 0; i < board.size(); ++i)
        {
            std::unordered_set<int> vals;
            for (int j = 0; j < board[i].size(); ++j)
            {
                const int valchar = board[i][j];
                if (valchar == '.')
                {
                    continue;
                }
                const int val = static_cast<int>(valchar - '0');
                if (vals.contains(val))
                {
                    return false;
                }
                vals.insert(val);
            }
        }

        // loop over the columns
        for (int j = 0; j < board[0].size(); ++j)
        {
            std::unordered_set<int> vals;
            for (int i = 0; i < board.size(); ++i)
            {
                const int valchar = board[i][j];
                if (valchar == '.')
                {
                    continue;
                }
                const int val = static_cast<int>(valchar - '0');
                if (vals.contains(val))
                {
                    return false;
                }
                vals.insert(val);
            }
        }
        return true;
    }
};
