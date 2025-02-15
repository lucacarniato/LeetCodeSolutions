class Solution994 {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // 1 count the fresh oranges, and find the positions of the rotten ones (seed)
        std::queue<std::tuple<int,int, int>> q;
        int num_fresh_oranges = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i < n;++i)
        {
            for(int j=0; j < m ;++j)
            {
                const auto v = grid[i][j];
                if(v == 1)
                {
                    num_fresh_oranges++;
                }
                if(v == 2)
                {
                    q.push({i,j,0});
                    visited[i][j] = true;
                }
            }
        }

        if(num_fresh_oranges == 0)
        {
            return 0;
        }


        // 2 for each rotten perform dfs until fresh oranges or seed
        std::array<int, 4> nx{-1,1,0,0};
        std::array<int, 4> ny{0,0,-1,1};
        int result = -1;
        int time = 0; 
        while(!q.empty())
        {
            const auto [i, j, p] = q.front();
            time = p;
            q.pop();
            for(int k=0; k< 4;k++)
            {
                int ni_new = i + nx[k];
                int nj_new = j + ny[k];
                if(ni_new>=0 && ni_new < n && nj_new>=0 && nj_new< m && !visited[ni_new][nj_new])
                {
                    visited[ni_new][nj_new] = true;
                    if(grid[ni_new][nj_new]!= 0 && grid[ni_new][nj_new]!= 2)
                    {
                        q.push({ni_new,nj_new, p + 1});
                        num_fresh_oranges--;
                    }
                }
            }
        }
        return num_fresh_oranges == 0 ? time : -1;
    }
};