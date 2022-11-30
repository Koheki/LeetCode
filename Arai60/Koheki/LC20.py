class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pair = {')':'(','}':'{',']':'['}

        for c in s:
            if c in pair:
                if stack and pair[c] == stack.pop():
                    continue
                return False
            else:
                stack.append(c)

        if not stack:
            return True
        else:
            return False