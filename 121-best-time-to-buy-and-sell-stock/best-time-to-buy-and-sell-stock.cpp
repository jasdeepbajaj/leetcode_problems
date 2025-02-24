class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left_buy = 0;
        int right_sell = 1;
        int maxProfit = 0;
        while (right_sell < n){
            if (prices[right_sell] > prices[left_buy]){
                int profit =  prices[right_sell] - prices[left_buy];
                maxProfit = max(profit, maxProfit);
            }
            else{
                left_buy = right_sell;
            }
            right_sell++;
        }   
        return maxProfit;
    }
};