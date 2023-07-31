class Solution {
public:

    int minimumDeleteSum(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        int rsum = 0;
        for(int j = 0;j<m;j++)
        {
            rsum += s1[j];
            dp[j+1][0] = rsum;
        }
        rsum = 0;
        for(int j = 0;j<n;j++)
        {
            rsum += s2[j];
            dp[0][j+1] = rsum;
        }
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i][j-1]+s2[j-1],dp[i-1][j]+s1[i-1]);
                }
            }
        }
        return dp[m][n];
    }
};