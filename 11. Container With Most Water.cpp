class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size()-1;
        int area = 0;
        while(left<right)
        {
            int temp = min(height[right],height[left])*(right-left);
            area = max(area,temp);
            if(height[left]>height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return area;
    }
};a