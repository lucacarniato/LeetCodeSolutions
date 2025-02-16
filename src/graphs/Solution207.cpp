class Solution207 {
 
     bool dfs(std::vector<std::vector<int>>& adj, 
              std::unordered_set<int>& courses_in_path, 
              std::vector<bool>& completed, 
              int course)
     {
        if(adj[course].empty() || completed[course])
        {
            return true;
        }
        if(courses_in_path.contains(course))
        {
            return false;
        }
        courses_in_path.emplace(course);

        for(const auto& c: adj[course])
        {
            if(!dfs(adj,courses_in_path, completed, c))
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
                   vector<vector<int>>& prerequisites) 
    {
        std::vector<std::vector<int>> adj(numCourses);
        for(const auto& p :prerequisites)
        {
            if (p[0] == p[1])
            {
                return false;
            }
            adj[p[0]].push_back(p[1]);
        }
        std::unordered_set<int> courses_in_path; 
        std::vector<bool> completed(numCourses, false);

        for(int i=0; i< numCourses;++i)
        {
            if(!dfs(adj, courses_in_path,  completed, i))
            {
                return false;
            }
        }
        return true;
    }
};