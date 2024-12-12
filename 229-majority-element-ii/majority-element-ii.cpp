class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto num: nums) mpp[num]++;

        vector<int> ans;
        for(auto it : mpp){
            if (it.second > nums.size() / 3) ans.push_back(it.first);
        }

        return ans;
    }
};