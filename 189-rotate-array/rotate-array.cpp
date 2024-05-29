class Solution {

// private:
//     void reverse(vector<int>& sub_array){
//         int j = sub_array.size()-1
        
//         for(int i = 0; i<=sub_array.size()/2; i++){
//             swap(sub_array[i], sub_array[j])
//             j--;
//         }
//     }

public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k%n;

        reverse(nums.end()-k, nums.end());
        // for(int i = 0; i<n; i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.begin(), nums.end());
        
        
    }
};