class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Initialize a pointer i to track the position of unique elements
        int i = 0;
        
        // Iterate through the array starting from the second element
        for (int j = 1; j < nums.size(); j++) {
            // If the current element is different from the last unique element
            if (nums[j] != nums[i]) {
                // Move the pointer i forward and update the next unique position with the current element
                nums[i + 1] = nums[j];
                i++;  // Increment the unique element index
            }
        }
        
        // Return the number of unique elements (i + 1 since i is zero-indexed)
        return i + 1;
    }
};
