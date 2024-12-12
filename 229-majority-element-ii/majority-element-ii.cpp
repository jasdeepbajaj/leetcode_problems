class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        int min = (int)(nums.size()/3) + 1;
        for(auto num: nums) {
            mpp[num]++;
            if (mpp[num] == min) ans.push_back(num);  
            if (ans.size() == 2) break;  
        }

        // for(auto it : mpp){
        //     if (it.second > nums.size() / 3) ans.push_back(it.first);
        // }

        return ans;
    }
};