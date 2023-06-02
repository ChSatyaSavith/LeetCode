class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        return binarySearch(nums,0,nums.size()-1,target);
    }

    int binarySearch(vector<int> nums,int left,int right,int target)
    {
        if(left>=right)
        {
            if(target>nums[left])
            {
                return left+1;
            }
            return left;
        }
        int mid = (left+right)/2;

        if(target==nums[mid])
        {
            return mid;
        }
        else if(target>nums[mid])
        {
            return binarySearch(nums,mid+1,right,target);
        }
        else
        {
            return binarySearch(nums,left,mid-1,target);
        }
    }
};