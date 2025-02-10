#include <vector>
using namespace std;

class Solution79
{

    int m_ = 0;
    int n_ = 0;

    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int p)
    {
        if (p == word.size())
        {
            return true;
        }

        if (i < 0 || i >= m_ ||
            j < 0 || j >= n_ ||
            word[p] != board[i][j])
            return false;

        const auto c = board[i][j];
        board[i][j] = '#';

        const auto res = dfs(board, word, i + 1, j, p + 1) ||
                         dfs(board, word, i - 1, j, p + 1) ||
                         dfs(board, word, i, j + 1, p + 1) ||
                         dfs(board, word, i, j - 1, p + 1);

        board[i][j] = c;

        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word)
    {
        m_ = board.size();
        n_ = board[0].size();

        for (int i = 0; i < m_; ++i)
        {
            for (int j = 0; j < n_; ++j)
            {
                if (dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
