class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<int> postfix(n,0);
        vector<int> result(n,0);

        prefix[0] = 1;
        postfix[n-1] = 1;
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for(int i = n-2; i >= 0; i--){
            postfix[i] = postfix[i+1] * nums[i+1];
        }
        for(int i = 0; i < n; i++){
            result[i] = prefix[i] * postfix[i];
        }

        return result;
    }   
};