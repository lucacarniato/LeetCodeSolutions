class Solution684TopologicalSort
{

public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges)
    {
        int n = edges.size();
        std::vector<int> degree(n + 1);
        std::vector<std::vector<int>> adj(n + 1);
        for (int i = 0; i < edges.size(); ++i)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        std::queue<int> q;
        for (int i = 0; i < n + 1; ++i)
        {
            if (degree[i] == 1)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            const auto n = q.front();
            q.pop();
            degree[n]--;

            for (int i = 0; i < adj[n].size(); ++i)
            {
                const auto nei = adj[n][i];
                degree[nei]--;
                if (degree[nei] == 1)
                {
                    q.push(nei);
                }
            }
        }
        for (int i = edges.size() - 1; i >= 0; --i)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if (degree[u] > 0 && degree[v] > 0)
            {
                return {u, v};
            }
        }
        return {};
    }
};

class SolutionUnionFind
{

    std::vector<int> parents_;
    std::vector<int> ranks_;

    int find(int n)
    {
        if (n == parents_[n])
        {
            return n;
        }
        parents_[n] = find(parents_[n]); // path compression
        return parents_[n];
    }

    bool Union(int u, int v)
    {
        int root_u = find(u);
        int root_p = find(v);

        if (root_p == root_u)
        {
            return false;
        }

        if (ranks_[root_p] > ranks_[root_u])
        {
            parents_[root_u] = root_p;
            ranks_[root_p] += ranks_[root_u];
        }
        else
        {
            parents_[root_p] = root_u;
            ranks_[root_u] += ranks_[root_p];
        }

        return true;
    }

public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges)
    {
        // Construct the graph
        int n = edges.size();
        parents_.resize(n + 1);
        for (int i = 0; i < n; ++i)
        {
            parents_[i] = i;
        }
        ranks_.resize(n + 1, 0);

        for (const auto& e : edges)
        {
            const auto u = e[0];
            const auto v = e[1];
            if (!Union(u, v))
            {
                return e;
            }
        }
        return {};
    }
};

class Solution684
{

    bool HasCycle(std::vector<std::vector<int>>& adj,
                  int current_node,
                  int previous_node,
                  std::unordered_set<int>& nodes_in_path)
    {
        if (nodes_in_path.contains(current_node))
        {
            return true;
        }
        nodes_in_path.emplace(current_node);

        for (const auto& neighbour : adj[current_node])
        {
            if (neighbour == previous_node)
                continue;
            if (HasCycle(adj, neighbour, current_node, nodes_in_path))
            {
                return true;
            }
        }
        nodes_in_path.erase(current_node);
        return false;
    }

public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges)
    {
        // Construct the graph
        int n = edges.size();
        std::vector<std::vector<int>> adj(n + 1);
        std::unordered_set<int> nodes_in_path;
        for (const auto& e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            if (HasCycle(adj, e[0], -1, nodes_in_path))
            {
                return e;
            }
        }
        return {};
    }
};
