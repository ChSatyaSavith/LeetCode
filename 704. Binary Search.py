class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        left = 0
        right = len(nums)-1

        while(left<=right):
            mid = (left+right)/2
            
            if(target==nums[mid]):
                return mid
            if(target<nums[mid]):
                right = mid - 1
                continue
            else:
                left = mid + 1
                continue
                
        return -1