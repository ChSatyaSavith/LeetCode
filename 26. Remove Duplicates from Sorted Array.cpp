class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int k = 1;

        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                nums[k] = nums[i+1];
                k+=1;
            }
        }
        return k;
    }
};