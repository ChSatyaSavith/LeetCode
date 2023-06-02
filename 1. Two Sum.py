class Solution(object):
    def twoSum(self, nums, target):
        hashTable = {}
        n = len(nums)

        for i in range(n):
            temp = target - nums[i]
            if temp not in hashTable:
                hashTable[nums[i]] = i
            else:
                return [hashTable[temp],i]
