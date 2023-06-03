class Solution {
public:

    int dfs(int head,vector<pair<int,int>> adj[],vector<int>& informTime)
    {
        int ans = 0;
        for(auto i: adj[head])
        {
            ans = max(ans,informTime[head] + dfs(i.first,adj,informTime));
        }
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<pair<int,int>> adj[n];
        
        for(int i = 0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                adj[manager[i]].push_back({i,informTime[i]});
            }
        }
        
        int ans = dfs(headID,adj,informTime);
        return ans;
    }
};