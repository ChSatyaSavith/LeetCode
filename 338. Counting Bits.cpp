class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr;
        arr.push_back(0);

        for(int i = 1;i<=n;i++)
        {
            if(i%2==0)
            {
                arr.push_back(arr[i/2]);
            }
            else
            {
                arr.push_back(arr[i/2]+1);
            }
        }
        return arr;
    }
};