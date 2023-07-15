class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference)
    {
        unordered_map<int, int> Hashmap;
        vector<int> dp(arr.size(),0);
        int ans = INT_MIN;

        for(int i = 0;i<arr.size();i++)
        {
            int temp = arr[i] - difference;
            
            if(Hashmap.count(temp))
            {
                dp[i] = dp[Hashmap[temp]] + 1;
            }
            else
            {
                dp[i] = 1;
            }
            Hashmap[arr[i]] = i;
            ans = max(ans,dp[i]);

        }
        return ans;
        
    }
};