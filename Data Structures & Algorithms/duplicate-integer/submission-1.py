class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        cs = set()
        for n in nums:
            if n in cs:
                return True
            cs.add(n)
        return False
        