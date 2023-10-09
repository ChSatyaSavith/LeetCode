class Solution {
public:
    string convert(string s, int numRows) 
    {
        vector<vector<char>> store;
        int n = numRows;
        if(n==1)
        {
            return s;
        }
        for(int i = 0;i<n;i++)
        {
            vector<char> temp;
            store.push_back(temp);
        }
        bool straight = true;
        int j = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(j<n && straight)
            {
                store[j].push_back(s[i]);
                j+=1;
                if(j==n)
                {
                    straight = false;
                    j-=2;
                }
            }
            else
            {
                store[j].push_back(s[i]);
                j-=1;
                if(j<0)
                {
                    straight = true;
                    j+=2;
                }
            }
        }

        string toreturn = "";
        for(auto x:store)
        {
            for(auto y:x)
            {
                toreturn.push_back(y);
            }
        }
        return toreturn;
    }
};