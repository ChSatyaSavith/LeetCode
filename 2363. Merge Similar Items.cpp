bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2)
    {
        sort(items1.begin(),items1.end(),sortcol);
        sort(items2.begin(),items2.end(),sortcol);

        vector<vector<int>> toreturn;
        
        int size = items1[items1.size()-1][0] > items2[items2.size()-1][0] ? items1[items1.size()-1][0] : items2[items2.size()-1][0];
        int val[size+1];
        memset(val, 0, sizeof(val));

        for(auto x: items1)
        {
            val[x[0]] += x[1];
        }
        for(auto x: items2)
        {
            val[x[0]] += x[1];
        }

        for(int i = 0;i<size+1;i++)
        {
            if(val[i]!=0)
            {
                toreturn.push_back({i,val[i]});
            }
        }
        return toreturn;


    }
};