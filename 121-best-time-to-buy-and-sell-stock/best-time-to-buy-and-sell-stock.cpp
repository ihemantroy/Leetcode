class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int profit = 0;
        int minPrice = INT_MAX;
        for(int price: prices)
        {
            minPrice = min(minPrice,price);
            profit = price - minPrice;
            maxProfit = max(profit,maxProfit);
        }
        return maxProfit;
    }
};