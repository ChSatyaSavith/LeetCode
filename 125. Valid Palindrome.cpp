class Solution {
public:
    bool isPalindrome(string s)
    {
        string toreturn = "";

        for(auto x: s)
        {
            if(iswalnum(x))
            {
                toreturn+=tolower(x);
            }
        }
        string x = toreturn;
        reverse(toreturn.begin(),toreturn.end());
        return x==toreturn;
    }
};