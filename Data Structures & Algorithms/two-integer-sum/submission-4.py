class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nm = {}
        for i, n in enumerate(nums):
            nm[n] = i
        
        for i, n in enumerate(nm):
            if target - n in nm:
                j = nm[target - n]
                if i != j:
                    return [min(i, j), max(i, j)]
        return [0, 1]