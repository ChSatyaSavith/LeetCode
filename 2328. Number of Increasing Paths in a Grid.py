class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        result = m*n

        def solve(r,c,mem={}):
            dir = [[0,1],[0,-1],[1,0],[-1,0]]
            ans = 0
            if (r,c) in mem:
                return mem[(r,c)]
            for a,b in dir:
                nr,nc = r+a,c+b

                if(nr>=0 and nc>=0 and nr<n and nc<m and grid[r][c]<grid[nr][nc]):
                    ans += 1+solve(nr,nc,mem)

            mem[(r,c)] = ans

            return ans

        for i in range(n):
            for j in range(m):
                result+=(solve(i,j))
        MOD = 10**9 + 7
        
        return result%MOD