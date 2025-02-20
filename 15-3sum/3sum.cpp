class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort array to enable two-pointer approach and duplicate handling
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        // Iterate through each element as potential first triplet element
        for(int i = 0; i < nums.size(); ++i) {
            // Skip duplicate elements for the first position
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            // Initialize two pointers for remaining elements
            int j = i + 1;
            int k = nums.size() - 1;
            
            // Two-pointer technique to find complementary pairs
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                // Adjust pointers based on sum value
                if (sum < 0) {
                    j++; // Need larger values
                } else if (sum > 0) {
                    k--; // Need smaller values
                } else {
                    // Store valid triplet and update pointers
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    // Move pointers and skip duplicates for second/third elements
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};
