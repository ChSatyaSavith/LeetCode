class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 1;
        int right = 2;

        //Finding Big range
        while(right<=numbers.size() && numbers[left-1]+numbers[right-1]<=target)
        {
            right++;
        }
        right -= 1;

        while(numbers[left-1]+numbers[right-1]!=target)
        {
            if(numbers[left-1]+numbers[right-1]<target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        vector<int> toreturn;
        toreturn.push_back(left);
        toreturn.push_back(right);
        return toreturn;
    }
};