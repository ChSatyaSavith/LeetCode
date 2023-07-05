class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        //TLE Error 73/74 test cases
        // int count = 0;

        // for(int i = 0;i<nums.size();i++)
        // {
        //     bool flag = false;
        //     if(nums[i]==0)
        //     {
        //         continue;
        //     }
        //     int temp = 0;
        //     for(int j = i;j<nums.size();j++)
        //     {
        //         temp += nums[j];
        //         if(nums[j]==0)
        //         {
        //             if(flag)
        //             {
        //                 break;
        //             }
        //             else
        //             {
        //                 flag = true;
        //             }
        //         }
        //     }
        //     count = max(count,temp);
        //     if(count==nums.size())
        //     {
        //         return count-1;
        //     }
        //     if(count>nums.size()/2)
        //     {
        //         return count;
        //     }
        // }
        // return count;

        int a = 0,b=0,c=0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                a++;
            }
            else
            {
                b=a;
                a=0;
            }
            c = max(c,b+a); //idk what this means
        }
        if(c==nums.size())
        {
            return c-1;
        }
        else
        {
            return c;
        }
        
    }
};