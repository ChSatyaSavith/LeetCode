class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        // int ans = INT_MAX;
        // for(int i = 0;i<nums.size();i++)
        // {
        //     int sum = nums[i];
        //     if(sum>=target)
        //     {
        //         return 1;
        //     }
        //     int count = 1;
        //     for(int j = i+1;j<nums.size();j++)
        //     {
        //         sum+=nums[j];
        //         count++;
        //         if(sum>=target)
        //         {
        //             ans = min(ans,count);
        //         }
        //     }
        // }
        // if(ans==INT_MAX)
        // {
        //     return 0;
        // }
        // return ans;

        int ans = INT_MAX;
        int curr = 0;
        int prev = 0;
        for(int i = 0;i<nums.size();i++)
        {
            curr+=nums[i];
            while(curr>=target) //window size chotta karte rahe till condition doesnt match this way we avoid TLE
            {
                ans = min(ans,i-prev+1);
                curr -= nums[prev];
                prev++;
            }
        }

        return ans==INT_MAX? 0:ans;
    }
};