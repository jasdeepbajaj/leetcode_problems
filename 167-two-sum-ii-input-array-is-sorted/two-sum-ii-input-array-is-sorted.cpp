class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Initialize two pointers, one starting at the beginning and the other at the end of the array
        int left = 0;
        int right = numbers.size() - 1;
        
        // Use a while loop to iterate until the two pointers meet
        while (left < right) {
            // Check if the sum of the numbers at the two pointers equals the target
            if (numbers[left] + numbers[right] == target) {
                // If the sum equals the target, return the indices (1-based index)
                return {left + 1, right + 1};
            }
            // If the sum is greater than the target, move the right pointer to the left
            else if (numbers[left] + numbers[right] > target) {
                right--;
            }
            // If the sum is less than the target, move the left pointer to the right
            else {
                left++;
            }
        }
        
        // If no solution is found, return {-1, -1} to indicate failure
        return {-1, -1};
    }
};
