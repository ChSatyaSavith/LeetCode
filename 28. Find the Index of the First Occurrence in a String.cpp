class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int m = needle.length();
        int lps[m];
        lps[0] = 0;
        int i = 1;
        int len = 0;

        while(i<m)
        {
            if(needle[i]==needle[len])
            {
                len+=1;
                lps[i] = len;
                i+=1;
            }
            else
            {
                if(len!=0)
                {
                    len = lps[len-1];
                }
                else
                {
                    lps[i] = 0;
                    i+=1;
                }
            }
        }

        int n = haystack.length();
        i = 0;
        int j = 0;

        while(i<n)
        {
            if(haystack[i]==needle[j])
            {
                i+=1;
                j+=1;

                if(j==m)
                {
                    return i-j;
                    j = lps[j-1];
                }
            }
            else if(i<n && needle[j]!=haystack[i])
            {
                if(j>0)
                {
                    j = lps[j-1];
                }
                else
                {
                    i+=1;
                }
            }

        }
        return -1;


    }
};