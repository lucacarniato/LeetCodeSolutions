class Solution62Second
{

public:
    int uniquePaths(int m, int n)
    {
        auto npaths = std::vector<int>(n, 1);
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                npaths[j] = npaths[j - 1] + npaths[j];
            }
        }

        return npaths[n - 1];
    }
};

class Solution62
{
    int m_;
    int n_;
    std::vector<std::vector<int>> p_;

    int f(int r, int c)
    {
        if (r >= m_ || c >= n_)
        {
            return 0;
        }
        if (p_[r][c] != -1)
        {
            return p_[r][c];
        }

        if (r == m_ - 1 && c == n_ - 1)
        {
            p_[r][c] = 1;
            return p_[r][c];
        }
        p_[r][c] = f(r + 1, c) + f(r, c + 1);
        return p_[r][c];
    }

public:
    int uniquePaths(int m, int n)
    {
        m_ = m;
        n_ = n;
        p_ = std::vector(m, std::vector(n, -1));
        return f(0, 0);
    }
};
