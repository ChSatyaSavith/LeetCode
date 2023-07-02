class Solution {
public:
    int ans = 0;
    vector<vector<int>> req;

    void backtrack(int index,int count,vector<int> transfers)
    {
        if(index==req.size())
        {
            for(int i: transfers)
            {
                if(i!=0)
                {
                    return;
                }
            }
            ans = max(ans,count);
            return;
        }

        transfers[req[index][0]]--;
        transfers[req[index][1]]++;
        backtrack(index+1,count+1,transfers);
        transfers[req[index][0]]++;
        transfers[req[index][1]]--;
        backtrack(index+1,count,transfers);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        req = requests;
        vector<int> transfers(n,0);
        backtrack(0,0,transfers);
        return ans;
    }
};