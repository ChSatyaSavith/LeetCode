class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int buy = prices[0];
        int maxprofit = 0;
        for(int i = 0;i<prices.size();i++)
        {
            if(prices[i]<buy)
            {
                buy = prices[i];
            }
            else if(prices[i] - buy > maxprofit)
            {
                maxprofit = prices[i] - buy;
            }
        }
        return maxprofit;
    }
};