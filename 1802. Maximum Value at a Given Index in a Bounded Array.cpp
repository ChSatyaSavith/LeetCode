class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        
        int l = 0;
        int r = maxSum;

        while(l<r)
        {
            const int m = (l+r)/2;
            if(getSum(n,index,m)>=maxSum)
            {
                r = m;
            }
            else
            {
                l = m+1;
            }
        }

        return getSum(n,index,l) > maxSum? l:l+1;
        
    }

    long getSum(int n,int index,int x)
    {
        long l = min(index,x-1);
        long r = min(n-index,x);
        long lsum = ((x-1)+(x-1 - l + 1))*l/2;
        long rsum = (x+(x-r+1))*r/2;

        return lsum+rsum;
    }
};