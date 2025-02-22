class Solution684 {

    bool HasCycle(std::vector<vector<int>>& adj,
    int current_node, 
    int previous_node, 
    std::unordered_set<int>& nodes_in_path)
    {
        if(nodes_in_path.contains(current_node))
        {
            return true;
        }
        nodes_in_path.emplace(current_node);

        for(const auto& neighbour: adj[current_node])
        {
            if(neighbour == previous_node) continue;
            if(HasCycle(adj, neighbour, current_node, nodes_in_path))
            {
                return true;
            }
        }
        nodes_in_path.erase(current_node); 
        return false;
    }



public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {        
        // Construct the graph
        int n = edges.size();
        std::vector<vector<int>> adj(n + 1);
        std::unordered_set<int> nodes_in_path;
        for(const auto& e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            if(HasCycle(adj, e[0], - 1, nodes_in_path))
            {
                return e;
            }
        }
        return {};        
    }
};