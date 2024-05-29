class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k%n;
        // if(new_k!=0){
        //     for(int i = 0; i<new_k; i++){
        //         int temp = nums[n-1];
        //         nums.insert(nums.begin(), nums[n-1]);
        //         nums.erase(nums.end()-1);
        //     }
        // }
        vector<int> temp;
        temp.insert(temp.end(), nums.end()-k, nums.end());
        for(int i = n-1; i>=k; i--){
            nums[i]=nums[i-k];
        }

        for(int i = 0; i<k; i++){
            nums[i]=temp[i];
        }
        
        
    }
};