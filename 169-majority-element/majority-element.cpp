class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's Voting Algorithm
        int count = 0;
        int el;
        
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                count = 1;
                el = nums[i];  // Set the current element as the candidate
            } else if (nums[i] == el) {
                count++;  // Increment count if the current element is the candidate
            } else {
                count--;  // Decrement count if the current element is not the candidate
            }
        }
        
        return el;  // Return the candidate which is the majority element
    }
};
