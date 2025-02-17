class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i< nums.size(); ++i){
            nums[i] = nums[i] * nums[i];
        }

        int head = 0;
        int tail = nums.size() - 1;
        int n = nums.size();
        vector<int> nums1(n, 0);
        for (int i = n - 1 ; i >= 0; i--){
            if (nums[tail] >= nums[head]){
                nums1[i] = nums[tail];
                tail --; 
            }
            else{
                nums1[i] = nums[head];
                head++;
            }
        }

        return nums1;
    }
};