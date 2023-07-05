class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        vector<int> result;
        for(int i = 0;i<32;i++)
        {
            int one = 0;
            int zero = 0;
            for(auto x: nums)
            {
                if((x>>i)&1)
                {
                    one+=1;
                }
                else
                {
                    zero+=1;
                }
            }

            one %= 3;
            zero %= 3;

            if(one==0)
            {
                result.push_back(0);
            }
            if(zero==0)
            {
                result.push_back(1);
            }
        }
        long  ans = 0;
        for(int i = 0;i<32;i++)
        {
            ans += result[i]*long(pow(2,i));
        }

        return ans;
    }
};