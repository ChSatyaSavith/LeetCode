class Solution {
public:
    int aheadBuy = 0;
    int aheadNotBuy = 0;

    int curBuy,curNotbuy;
    int maxProfit(vector<int>& prices, int fee) 
    {
        for(int i = prices.size()-1;i>=0;i--)
        {
            curBuy = max(-prices[i]+aheadNotBuy,0+aheadBuy);
            curNotbuy = max(prices[i]+aheadBuy-fee,0+aheadNotBuy);

            aheadBuy = curBuy;
            aheadNotBuy = curNotbuy;
        }
        return aheadBuy;
    }
};