class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        product = 1
        flag = False
        count = 0
        for i in nums:
            if(i==0):
                flag = True
                count+=1
            if(i!=0):
                product *= i
        arr = []

        for i in range(len(nums)):
            if(flag):
                if(nums[i]!=0 or count>1):
                    arr.append(0)
                elif(nums[i]==0 and count==1):
                    arr.append(product)
            else:
                arr.append(product/nums[i])
        return arr

            

        