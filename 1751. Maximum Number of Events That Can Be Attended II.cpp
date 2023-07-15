class Solution 
{
public:
    vector<vector<int>> event;
    vector<vector<int>> dp;

    int binary(int target)
    {
        int left = 0;
        int right = event.size();
        while(left<right)
        {
            int mid = (left+right)/2;
            if(event[mid][0]<=target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;

    }
    int dfs(int index,int count)
    {
        if(index==event.size() || count == 0)
        {
            return 0;
        }
        if(dp[count][index]!=-1)
        {
            return dp[count][index];
        }
        int next = binary(event[index][1]);
        dp[count][index] = max(event[index][2] + dfs(next,count-1),dfs(index+1,count));
        return dp[count][index];

    }
    int maxValue(vector<vector<int>>& events, int k) 
    {
        event = events;
        sort(event.begin(),event.end());

        vector<vector<int>> dps(k+1,vector<int>(events.size(),-1));
        dp = dps;
        return dfs(0,k);
    }
};