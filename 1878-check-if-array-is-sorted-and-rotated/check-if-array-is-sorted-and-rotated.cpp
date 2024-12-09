class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;

        int pivot_ind = -1;
        int count = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                count++;
                pivot_ind = i;
            }
        }

        if (count==0) return true;
        else if(count>1) return false;

        for (int i = pivot_ind + 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }

        if (nums[n - 1] > nums[0]) {
            return false;
        }

        return true;
    }
};
