class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> dict;
        for(auto itr: nums){
            if(dict[itr]>=2) continue;
            else dict[itr]++;
        }

        vector<int> ans;
        nums.clear();
        for(auto itr: dict){
            while(itr.second!=0){
                nums.push_back(itr.first);
                itr.second--;
            }
        }
        // int m = nums.size();
        // int n = ans.size();

        // nums.clear();

        // for (int i= 0; i<n; i++){
        //     nums[i] = ans[i];
        // }

        return nums.size();
    }
};