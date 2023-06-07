class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(auto x:nums)
        {
            if(x!=val)
            {
                nums[index] = x;
                index++;
            }
        }
        return index;
    }
};