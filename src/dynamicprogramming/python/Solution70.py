# bottom-down
class Solution70:
    def climbStairs(self, n: int) -> int:

        if n <= 2:
            return n
        end = 1
        one_before_end = 1
        for i in range(n - 1):
            temp = one_before_end
            one_before_end = one_before_end + end
            end = temp
        return one_before_end        
# top-down
class Solution70:
    def climbStairs(self, n: int) -> int:

        num_comb = dict()
        def f(t):
            if t in num_comb:
                return num_comb[t]

            if t >= n:
                return 1 if t == n else 0 
            
            take_1 =  f(t + 1)
            take_2 =  f(t + 2)
            num_comb[t] = take_1+ take_2
            return num_comb[t]
    
        return f(0)