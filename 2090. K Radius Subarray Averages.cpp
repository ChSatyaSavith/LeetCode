class Solution {
public:
    vector<long long int> prefixSum;

    void createArr(vector<int> nums)
    {
        prefixSum.push_back(nums[0]);
        for(int i = 1;i<nums.size();i++)
        {
            long long int temp = nums[i]+prefixSum[i-1];
            prefixSum.push_back(temp);
        }
    } //ye to shi hai
    vector<int> getAverages(vector<int>& nums, int k)
    {
        createArr(nums);
        vector<int> toreturn;

        for(int i = 0;i<nums.size();i++)
        {
            int left = i-k;
            int right = i+k;
            if(left<0 || right>nums.size()-1)
            {
                toreturn.push_back(-1);
            }
            else
            {
                if(left==0)
                {
                    toreturn.push_back(prefixSum[right]/(2*k+1));
                }
                else if(left!=0)
                {
                    toreturn.push_back((prefixSum[right]-prefixSum[left-1])/(2*k+1));
                }
            }
        }
        return toreturn;

    }
};