class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        ///Counting freuquencies
        map<int,int> mp;
        unordered_set<int> unique;
        for(auto x: arr)
        {
            auto it = mp.find(x);
            if(it!=mp.end())
            {
                mp[x]+=1;
            }
            else
            {
                mp.insert({x,0});
            }
        }

        for(auto it: mp)
        {
            if(unique.find(it.second)!=unique.end())
            {
                return false;
            }
            unique.insert(it.second);
        }
        return true;
    }
};