class Solution {
public:
    long long putMarbles(vector<int>& weights, int k)
    {
        vector<int> pairs(weights.size()-1,0);

        for(int i = 1;i<weights.size();i++)
        {
            pairs[i-1] = weights[i] + weights[i-1];
        }

        sort(pairs.begin(),pairs.end());
        long long min = 0;
        long long max = 0;

        for(int i = 0;i<k-1;i++)
        {
            min += pairs[i];
            max += pairs[weights.size()-2-i];
        }

        return max-min;

    }
};