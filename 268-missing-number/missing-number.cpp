class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //brute force -- Linear Search
        //TC = O(n^2)
        bool found;
        int ans;
        for (int i = 0; i <= nums.size(); ++i){
            found = false;
            for(int num : nums){
                if(num == i){
                    found = true;
                    break;
                }
            }
            if (!found) ans = i;
        }

        return ans;
    }
};