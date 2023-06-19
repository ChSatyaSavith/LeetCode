class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int a = 0;

        vector<int> alt;
        alt.push_back(0);

        for(int i = 1;i<=gain.size();i++)
        {
            alt.push_back(gain[i-1]+alt[i-1]);
            if(alt[i]>a)
            {
                a = alt[i];
            }
        }
        return a;
    }
};