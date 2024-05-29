class Solution {

private:
    void Reverse(vector<int>& arr, int start, int end){
        while (start<=end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k%n;

        // reverse(nums.end()-k, nums.end());
        // // for(int i = 0; i<n; i++){
        // //     cout<<nums[i]<<" ";
        // // }
        // // cout<<endl;
        // reverse(nums.begin(), nums.end()-k);
        // reverse(nums.begin(), nums.end());

        Reverse(nums, n-k, n-1);
        Reverse(nums, 0, n-k-1);
        Reverse(nums, 0, n-1);
        
        
    }
};