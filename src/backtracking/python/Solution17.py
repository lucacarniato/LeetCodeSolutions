class Solution17:

    def letterCombinations(self, digits: str) -> List[str]:
        
        if not digits:
            return []

        digit_to_letters = {
             '2': ['a', 'b', 'c'],
             '3': ['d', 'e', 'f'],
             '4': ['g', 'h', 'i'],
             '5': ['j', 'k', 'l'],
             '6': ['m', 'n', 'o'],
             '7': ['p', 'q', 'r', 's'],
             '8': ['t', 'u', 'v'],
             '9': ['w', 'x', 'y', 'z']
             }

        def f(p, local_result, result):
            
            if p == len(digits):
                result.append("".join(local_result))
                return

            current_char = digits[p]
            for c in digit_to_letters[current_char]:
                local_result.append(c)
                f(p + 1, local_result, result)
                local_result.pop()

        result = []
        local_result = []
        f(0, local_result, result)

        return result