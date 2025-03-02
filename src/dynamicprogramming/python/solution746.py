# bottom - up
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:

        dp = [0] * len(cost)
        dp[len(cost) - 1] = cost[-1]
        dp[len(cost) - 2] = cost[-2]
        
        for i in range(len(cost) - 3, -1, -1):
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2])
        return min(dp[0], dp[1])

# top down  + memonization
class Solution746:
    def minCostClimbingStairs(self, cost: List[int]) -> int:

        if len(cost)==1:
            return cost[0]

        mem = dict()
        def f(p):
            
            if p >= len(cost):
                return 0

            if p in mem:
                return mem[p]

            cost_1 = cost[p] + f(p + 1)
            cost_2 = cost[p] + f(p + 2)

            mem[p] = min(cost_1, cost_2)

            return mem[p]

        return min(f(0), f(1))
