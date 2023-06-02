class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int change  = start ^ goal;
        int count = 1;
        while(change = change & (change-1))
        {
            count++;
        }
        if(start==goal)
        {
            return 0;
        }
        return count;
    }
};