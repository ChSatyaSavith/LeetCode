class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost)
    {
        int constant = pow(10,6) + 2;
        vector<int> c(constant,0);
        
        for(int i = 0;i<nums.size();i++)
        {
            c[nums[i]] += cost[i];
        }

        vector<long long> prefix(constant,0);
        vector<long long> suffix(constant,0);
        long long sum = 0;
        for(int i = 1;i<constant;i++)
        {
            prefix[i] = prefix[i-1] + sum; //0 to 1 kabhi exist nhi karta
            sum+=c[i];
        }

        sum = 0;
        long long min = LLONG_MAX;
        for(int i = constant-2;i>=0;i--)
        {
            suffix[i] = suffix[i+1] + sum;
            sum+=c[i];

            min = min<suffix[i]+prefix[i]? min:suffix[i]+prefix[i]; 
        }

        return min;
    }
    
};