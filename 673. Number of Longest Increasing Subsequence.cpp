class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        vector<int> dp(nums.size(),1);
        vector<int> count(nums.size(),1);
        int max1 = 1;

        for(int i = 1;i<nums.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                    else if(dp[i]==dp[j]+1)
                    {
                        count[i] += count[j];
                    }
                }
            }
            max1 = max(max1,dp[i]);
        }

        int toreturn = 0;

        for(int i = 0;i<nums.size();i++)
        {
            if(dp[i]==max1)
            {
                toreturn += count[i];
            }
        }
        return toreturn;
    }
};