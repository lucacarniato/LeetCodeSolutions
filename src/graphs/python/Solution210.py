class Solution210:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:

        adj = {i: [] for i in range(numCourses)}
        for course, preRequisite in prerequisites:
            adj[course].append(preRequisite)

        visited_in_path = set()
        all_visited = set()
        result =  []

        def dfs(course):

            if course in visited_in_path: 
                return False
            
            if course in all_visited:  
                return True

            visited_in_path.add(course)
            for pre in adj[course]:
                if not dfs(pre):
                    return False  

            visited_in_path.remove(course)
            all_visited.add(course)
            result.append(course) 
            return True

        for c in range(numCourses):
            if c not in all_visited:
                if not dfs(c):
                    return [] 

        return result
