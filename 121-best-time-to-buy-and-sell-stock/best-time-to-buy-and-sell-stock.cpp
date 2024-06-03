class Solution {
public:
    int maxProfit(vector<int>& prices) {
        cout<<prices.size();
        int min_buy = prices[0];
        int max_prof = 0;
        for(int i =1; i<prices.size(); i++){
            int diff = prices[i] - min_buy;
            max_prof = max(max_prof, diff);
            min_buy = min(min_buy, prices[i]);
            
        }
        return max_prof;           
    }
};