class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered map to store the elements of the array and their indices
        unordered_map<int, int> dict; // element, index
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the difference needed to reach the target
            int diff_required = target - nums[i];
            
            // Check if the required difference is already in the map
            if (dict.find(diff_required) != dict.end()) {
                // If it is, return the current index and the index of the difference
                return {i, dict[diff_required]};
            } else {
                // If not, add the current element and its index to the map
                dict[nums[i]] = i;
            }
        }
        
        // Return an empty vector if no solution is found
        return {};
    }
};
