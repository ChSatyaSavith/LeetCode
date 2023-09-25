class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        #My implementation works for 308/312 test cases
        # nums.sort()
        # ans = []
        # hash = []

        # for i in range(len(nums)):
        #     for j in range(i+1,len(nums)):
        #         tofind = -1*(nums[i]+nums[j])
        #         if(tofind>0):
        #             continue
        #         temp = []
        #         if(tofind in hash):
        #             temp.append(nums[i])
        #             temp.append(nums[j])
        #             temp.append(tofind)
        #             temp.sort()
        #             ans.append(temp)
        #     hash.append(nums[i])
        # toreturn = []
        # for i in ans:
        #     if i not in toreturn:
        #         toreturn.append(i)
        # return toreturn
        ans = []
        nums.sort()
        for i, a in enumerate(nums):
            if(a>0):
                break

            if(i>0 and a==nums[i-1]):
                continue

            l = i+1
            r = len(nums)-1
            while(l<r):
                three_sum = a + nums[l] + nums[r]
                if(three_sum>0):
                    r-=1
                elif(three_sum<0):
                    l+=1
                else:
                    ans.append([a,nums[l],nums[r]])
                    l+=1
                    r-=1
                    while(nums[l]==nums[l-1] and l < r):
                        l+=1
        return ans

        

        