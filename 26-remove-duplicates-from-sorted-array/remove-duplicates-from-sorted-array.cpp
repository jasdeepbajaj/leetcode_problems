class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> unique_nums;
        // unique_nums.push_back(nums[0]);
        int num_to_be_pushed = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>num_to_be_pushed) {
                num_to_be_pushed = nums[i];
                unique_nums.push_back(num_to_be_pushed);
            }
        }

        for(int i = 0; i<unique_nums.size(); i++){
            cout<<unique_nums[i]<<" ";
        }
        
        nums.clear();
        for(int i = 0; i<unique_nums.size(); i++){
            nums.push_back(unique_nums[i]);
        }
        for(int i = 0; i<unique_nums.size(); i++){
            cout<<unique_nums[i]<<" ";
        }
        return unique_nums.size();
    }
};