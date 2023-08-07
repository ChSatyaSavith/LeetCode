class Solution {
public:
    bool flag = false;
    void binarySearch(vector<int> arr,int left,int right,int target)
    {
        while(left<=right)
        {
            int mid = (left+right)/2;

            if(arr[mid]==target)
            {
                flag = true;
                break;
            }
            else if(target<arr[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        for(auto x:matrix)
        {
            if(target<x[0] || flag)
            {
                break;
            }
            if(!flag)
            {
                binarySearch(x,0,x.size()-1,target);
            }

        }
        return flag;
    }
};