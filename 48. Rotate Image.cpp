class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i<j)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }

        for(int i = 0;i<n;i++)
        {
            int left = 0;
            int right = n-1;

            for(int j = 0;j<n/2;j++)
            {
                if(left>=right)
                {
                    continue;
                }
                else
                {
                    swap(matrix[i][left],matrix[i][right]);
                    left+=1;
                    right-=1;
                }
            }
        }
    }
};