class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto x: nums)
        {
            s.insert(x);
        }
        if(s.size()<nums.size())
        {
            return true;
        }
        return false;
    }
};
