class Solution {
public:
    int xorOperation(int n, int start) 
    {
        int store = start;
        if(n<=1)
        {
            return store;
        }
        else
        {
            for(int i = 1;i<n;i++)
            {
                store ^= start + 2*i;
            }

            return store;
        }
    }
};