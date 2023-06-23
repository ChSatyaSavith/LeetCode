class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        
        d = {}

        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                diff = nums[j]-nums[i]
                d[j,diff] = d.get((i,diff),1) +1

        return max(d.values())