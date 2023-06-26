class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:

        @lru_cache(None) #Memoization technique??

        def dfs(curr,rem):
            if(rem<0):
                return 0
            elif curr==finish:
                res = 1
            else:
                res = 0

            for  i in range(len(locations)):
                if(curr!=i):
                    cost = abs(locations[curr]-locations[i]) #fuel cost
                    res += dfs(i,rem - cost)

            return res % (10**9+7)
        
        return dfs(start,fuel)