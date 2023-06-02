class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int diff = x^y;
        int count = 1;
        while(diff&=diff-1)
        {
            count++;
        }
        if(x==y)
        {
            return 0;
        }
        else
        {
            return count;
        }
    }
};