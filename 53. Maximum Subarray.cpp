class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = 0;
        int maximum = nums[0];

        for(auto x: nums)
        {
            sum+=x;
            maximum = max(sum,maximum);
            if(sum<0)
            {
                sum = 0;
            }
        }
        return maximum;
    }
};