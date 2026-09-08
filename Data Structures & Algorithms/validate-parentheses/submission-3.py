class Solution:
    def isValid(self, s: str) -> bool:
        q = []
        matches = {
            '(': ')',
            '[': ']',
            '{': '}'
        }
        for c in s:
            if c in matches:
                q.append(c)
            else:
                if len(q) == 0:
                    return False
                op = q.pop()
                if matches[op] != c:
                    return False
        
        return len(q) == 0