class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Hashing
        int n = nums.size();
        vector<int> hashMap(n + 1, 0);

        int curr_num;
        for(int i = 0; i<n; ++i){
            curr_num = nums[i];
            hashMap[curr_num]++;
        }

        int ans;
        for(int i = 0; i<hashMap.size(); ++i){
            if (hashMap[i] == 0) ans = i;
        }

        return ans;
    }
};