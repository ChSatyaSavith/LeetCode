class Solution {
public:
    vector<vector<int>> toreturn;
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> arr;
        backtrack(arr,0,nums.size(),nums);
        return toreturn;
    }
    void backtrack(vector<int> arr,int i, int size,vector<int> nums)
    {
        toreturn.push_back(arr);
        if(i>=size)
        {
            return;
        }
        for(int j = i;j<size;j++)
        {
            arr.push_back(nums[i]);
            i+=1;
            backtrack(arr,i,size,nums);
            arr.pop_back();
        }
        return;
    }
};