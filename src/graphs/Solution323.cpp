class Solution323 {
public:
    int countComponents(int n, std::vector<std::vector<int>>& edges) 
    {
        std::vector<std::vector<int>> adj(n);
        for(int i=0; i < edges.size();++i)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
		
		std::vector<bool> visited(n, false);
		int result = 0;
		for(int i=0; i < n;++i)
		{
			if(visited[i]==true)
			{
				continue;
			}
			result++;
			std::queue<int> q;
			q.push(i);
			
			while(!q.empty())
			{
				const auto cn = q.front();
				q.pop();
				visited[cn] = true;
				
				for(const auto& nei: adj[cn])
				{
					if(visited[nei])
					{
						continue;
					}
					q.push(nei);
				}
			}	
		}
		return result;
    }
};