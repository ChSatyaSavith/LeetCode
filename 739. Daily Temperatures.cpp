class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> count(temperatures.size(),0);

        for(int i = temperatures.size()-2;i>=0;i--)
        {
            if(temperatures[i]<temperatures[i+1])
            {
                count[i] = 1;
            }
            else if(temperatures[i]>=temperatures[i+1] && count[i+1]==0)
            {
                count[i] = 0;
            }
            else if(temperatures[i]>=temperatures[i+1] && count[i+1]!=0)
            {
                int temp = i + count[i+1] + 1;
                while(temperatures[i]>=temperatures[temp] && count[temp]!=0)
                {
                    temp+=count[temp];
                }
                
                if(temperatures[i]>=temperatures[temp] && count[temp]==0)
                {
                    count[i] = 0;
                }
                else
                {
                    count[i] = temp-i;
                }
            }
        }
        return count;
    }
};