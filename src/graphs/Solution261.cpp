class Solution261 
{

    bool dfs(const std::vector<std::vector<int>>& adj, 
                 std::unordered_set<int>& nodes_in_path,
                 int node,
                 std::vector<bool>& completed,
                 int& parent)
                 {
                    if(completed[node] )
                    {
                        return false;
                    }
                    if(nodes_in_path.find(node)!= nodes_in_path.end())
                    {
                        return true;
                    }
                    nodes_in_path.emplace(node);
                    for(const auto neighbour: adj[node])
                    {
                        if(parent == neighbour)
                        {
                            continue;
                        }

                        if(dfs(adj, nodes_in_path,neighbour,completed, node))
                        {
                            return true;
                        }
                    }
                    completed[node] = true;
                    nodes_in_path.erase(node);
                    return false;
                 }

public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        if (edges.size() != n - 1) return false;

        std::vector<std::vector<int>> adj(n);
        for(const auto& e: edges)
        {
            if(e[0]==e[1])
            {
                return false;
            }

            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        std::unordered_set<int> nodes_in_path;
        std::vector<bool> completed(n, false);

        int parent = -1;
        if(dfs(adj, nodes_in_path, 0, completed, parent))
        {
            return false;
        }

        for (const auto& visited : completed) {
            if (!visited) {
                return false; 
            }
        }
        
        return true;
    }
};