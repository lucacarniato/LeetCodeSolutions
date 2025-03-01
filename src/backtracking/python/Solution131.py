class Solution:

    def partition(self, s: str) -> List[List[str]]:
        
        def is_palindrome(s, left, right):
            while left <right:
                if s[left] != s[right]:
                    return False
                left += 1
                right -=1
            return True

        def backtrack(start, s, path, result):
        
            if start == len(s):
                result.append(path[:])
                return

            for end in range(start, len(s)):
                
                if is_palindrome(s, start, end):
                    path.append(s[start:end + 1])
                    backtrack(end + 1, s, path, result)
                    path.pop()
        
        result = []
        backtrack(0, s, [], result)

        return result