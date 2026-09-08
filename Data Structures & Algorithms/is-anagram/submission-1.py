class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if (len(s) != len(t)):
            return False

        ch = {}
        for c in s:
            if c in ch:
                ch[c] += 1
            else:
                ch[c] = 1

        for c in t:
            if c not in ch:
                return False
            ch[c] -= 1

        for c in ch:
            if ch[c] != 0:
                return False
        return True  