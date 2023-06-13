class Solution(object):
    def equalPairs(self, grid):
        hash_map = {}
        count = 0
        for i in grid:
            s = '-'.join(map(str, i))
            if s not in hash_map.keys():
                hash_map[s] = 0
            else:
                hash_map[s]+=1

        for i in range(len(grid)):
            for j in range(i,len(grid)):
                temp = grid[i][j]
                grid[i][j] = grid[j][i]
                grid[j][i] = temp


        for i in grid:
            s = '-'.join(map(str, i))

            if s in hash_map.keys():
                count+=hash_map[s]+1

        return count

