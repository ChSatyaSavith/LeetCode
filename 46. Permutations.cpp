class Solution {
public:
    vector<vector<int>> output;

    void backtrack(vector<int> choose,vector<int> temp,vector<int> nums)
    {
        if(temp.size()==nums.size())
        {
            output.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(choose[i]==0)
            {
                choose[i] = 1;
                temp.push_back(nums[i]);
                backtrack(choose,temp,nums);
                choose[i] = 0;
                temp.pop_back();
            }
        }


    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> temp;
        vector<int> choose(nums.size(),0);
        backtrack(choose,temp,nums);
        return output;
    }
};