class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size()-1;
        int column = 0;
        int neg = 0;
        while(row>=0)
        {
            for(;column<grid[row].size();column++)
            {
                if(grid[row][column]<0)
                {
                    neg+=grid[row].size() - column;
                    break;
                }
            }
            row--;
        }

        return neg;

    }
};