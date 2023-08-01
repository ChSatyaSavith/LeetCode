class Solution {
public:
    vector<vector<int>> output;
    
    void backtrack(int n,int start,vector<int> temp,int k)
    {
        if(temp.size()==k)
        {
            output.push_back(temp);
            return;
        }

        for(int i = start;i<=n;i++)
        {
            temp.push_back(i);
            backtrack(n,i+1,temp,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> temp;
        backtrack(n,1,temp,k);
        return output;
    }
};