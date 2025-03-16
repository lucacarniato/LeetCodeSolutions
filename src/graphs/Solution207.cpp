class Solution207
{

    bool dfs(std::vector<std::vector<int>>& adj,
             std::unordered_set<int>& courses_in_path,
             std::vector<bool>& completed,
             int course)
    {
        if (adj[course].empty() || completed[course])
        {
            return true;
        }
        if (courses_in_path.contains(course))
        {
            return false;
        }
        courses_in_path.emplace(course);

        for (const auto& c : adj[course])
        {
            if (!dfs(adj, courses_in_path, completed, c))
            {
                return false;
            }
        }
        courses_in_path.erase(course);
        completed[course] = true;
        return true;
    }

public:
    bool canFinish(int numCourses,
                   std::vector<std::vector<int>>& prerequisites)
    {
        std::vector<std::vector<int>> adj(numCourses);
        for (const auto& p : prerequisites)
        {
            if (p[0] == p[1])
            {
                return false;
            }
            adj[p[1]].push_back(p[0]);
        }
        std::unordered_set<int> courses_in_path;
        std::vector<bool> completed(numCourses, false);

        for (int i = 0; i < numCourses; ++i)
        {
            if (!dfs(adj, courses_in_path, completed, i))
            {
                return false;
            }
        }
        return true;
    }
};

class Solution207BFS
{

public:
    bool canFinish(int numCourses,
                   std::vector<std::vector<int>>& prerequisites)
    {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> node_degrees(numCourses, 0);
        for (const auto& p : prerequisites)
        {
            if (p[0] == p[1])
            {
                return false;
            }
            adj[p[1]].push_back(p[0]);
            node_degrees[p[0]]++;
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (node_degrees[i] == 0)
            {
                q.push(i);
            }
        }

        int counter = 0;
        while (!q.empty())
        {
            const auto n = q.front();
            q.pop();
            counter++;
            for (const auto& neighbour : adj[n])
            {
                node_degrees[neighbour]--;
                if (node_degrees[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        return counter == numCourses;
    }
};
