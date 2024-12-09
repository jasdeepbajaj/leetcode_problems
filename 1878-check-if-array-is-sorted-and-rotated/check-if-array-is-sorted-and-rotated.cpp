class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;  // Edge case: a single element is trivially sorted

        int pivot_ind = -1;
        bool found_decrease = false;

        // Find the pivot (where the array starts decreasing)
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                if (found_decrease) {
                    // If we find a second decrease, return false
                    return false;
                }
                found_decrease = true;
                pivot_ind = i;
            }
        }

        // If no decrease was found, the array is already sorted
        if (!found_decrease) return true;

        // After finding the pivot, check if the rest of the array is non-decreasing
        for (int i = pivot_ind + 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }

        // Finally, check if the last element is less than or equal to the first element
        // to ensure the array can be rotated to become non-decreasing
        if (nums[n - 1] > nums[0]) {
            return false;
        }

        return true;
    }
};
