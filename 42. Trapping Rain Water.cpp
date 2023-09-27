class Solution {
public:
    int trap(vector<int>& height) 
    {
        vector<int> leftheight;
        vector<int> rightheight;

        int left = height[0];
        leftheight.push_back(left);

        int right = height[height.size()-1];
        rightheight.push_back(right);

        for(int i = 1;i<height.size();i++)
        {
            left = max(left,height[i]);
            leftheight.push_back(left);

            right = max(right,height[height.size()-1-i]);
            rightheight.push_back(right);
        }
        reverse(rightheight.begin(),rightheight.end());

        int res = 0;
        for(int i = 0;i<height.size();i++)
        {
            res += min(leftheight[i],rightheight[i]) - height[i];
        }
        return res;
    }
};