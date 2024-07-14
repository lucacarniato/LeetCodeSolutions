#include <queue>
#include <vector>

using namespace std;

class Solution200
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        std::vector<std::vector<bool>> isVisited(grid.size(), std::vector<bool>(grid[0].size(), false));
        int result = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {

                if (!isVisited[i][j] && grid[i][j] == '1')
                {
                    isVisited[i][j] = true;

                    result = result + 1;
                    std::queue<std::pair<int, int>> q;
                    q.push({i, j});

                    while (!q.empty())
                    {
                        auto [ci, cj] = q.front();
                        q.pop();
                        if (ci + 1 < grid.size() && !isVisited[ci + 1][cj] && grid[ci + 1][cj] == '1')
                        {
                            q.push({ci + 1, cj});
                            isVisited[ci + 1][cj] = true;
                        }
                        if (ci - 1 >= 0 && !isVisited[ci - 1][cj] && grid[ci - 1][cj] == '1')
                        {
                            q.push({ci - 1, cj});
                            isVisited[ci - 1][cj] = true;
                        }
                        if (cj + 1 < grid[0].size() && !isVisited[ci][cj + 1] && grid[ci][cj + 1] == '1')
                        {
                            q.push({ci, cj + 1});
                            isVisited[ci][cj + 1] = true;
                        }

                        if (cj - 1 >= 0 && !isVisited[ci][cj - 1] && grid[ci][cj - 1] == '1')
                        {
                            q.push({ci, cj - 1});
                            isVisited[ci][cj - 1] = true;
                        }
                    }
                }
                isVisited[i][j] = true;
            }
        }
        return result;
    }
};
