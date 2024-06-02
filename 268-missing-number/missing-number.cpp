class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        for (int i = 1; i <= n; i++){
            p^=i;
        }
        for (auto el:nums){
            p^=el;
        }

        return p;
    }
};