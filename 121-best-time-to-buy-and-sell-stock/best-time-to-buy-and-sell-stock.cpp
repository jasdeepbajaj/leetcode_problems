class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Print the size of the prices vector for debugging purposes
        cout << prices.size();
        
        // Initialize the minimum buying price to the first price in the array
        int min_buy = prices[0];
        
        // Initialize the maximum profit to 0
        int max_prof = 0;
        
        // Iterate over the prices starting from the second price
        for(int i = 1; i < prices.size(); i++) {
            // Calculate the potential profit if the stock was sold on day i
            int diff = prices[i] - min_buy;
            
            // Update the maximum profit if the current profit is greater
            max_prof = max(max_prof, diff);
            
            // Update the minimum buying price to the lowest price so far
            min_buy = min(min_buy, prices[i]);
        }
        
        // Return the maximum profit found
        return max_prof;
    }
};
