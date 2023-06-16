class Solution(object):
    def numOfWays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        def nCr(n, r):
            return (fact(n) / (fact(r) * fact(n - r)))

        def fact(n):
            if n == 0:
                return 1
            res = 1
            
            for i in range(2, n+1):
                res = res * i
                
            return res

        def ways(n):
            if(len(n)<=2):
                return 1
            root = n[0]

            l = [i for i in n if i<root]
            r = [i for i in n if i>root]

            return ways(l)*ways(r)*nCr(len(l)+len(r),len(r))

        return (ways(nums)-1)%(10**9+7)