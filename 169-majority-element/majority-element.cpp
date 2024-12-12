class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        int n = nums.size();

        for(int i = 0; i<n; ++i){
            int curr_num = nums[i];
            if(mpp.find(curr_num) != mpp.end()) mpp[curr_num]++;
            else mpp[curr_num] = 1;
        }

        for(auto it : mpp){
            int num = it.first;
            int count = it.second;
            if (count > n/2) return num; 
        }

        return -1; 
    }
};