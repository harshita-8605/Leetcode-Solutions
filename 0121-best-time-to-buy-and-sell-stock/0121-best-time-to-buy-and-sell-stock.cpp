class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 1;
        int currProfit = 0;
        int maxProfitt = 0;

        while(buy <= sell && sell < prices.size()){
            currProfit = prices[sell] - prices[buy];
            if(currProfit < 0){
                while(currProfit < 0 and buy <= sell){
                    buy++;
                    currProfit = prices[sell] - prices[buy];
                }
            }
            maxProfitt = max(currProfit, maxProfitt);
            sell++;
        }
        return maxProfitt;
    }
};