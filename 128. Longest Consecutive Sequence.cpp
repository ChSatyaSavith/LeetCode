class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int ans = 0;
        set<int> hash;
        for(auto x:nums)
        {
            hash.insert(x);
        }
        
        for(auto x:nums)
        {
            if(hash.contains(x-1)) //to check if this number is the start or not
            {
                continue;
            }
            else
            {
                int temp = x;
                int count = 0;
                while(hash.contains(temp))
                {
                    temp = temp+1;
                    count++;
                }
                ans = max(ans,count);
            }
        }

        return ans;
    }
};