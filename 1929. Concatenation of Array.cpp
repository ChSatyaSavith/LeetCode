class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        vector<int> toreturn(2*nums.size());

        for(int i = 0;i<nums.size();i++)
        {
            toreturn[i] = nums[i];
            toreturn[i+nums.size()] = nums[i];
        }

        return toreturn;
    }
};