class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n,0);
        vector<int> right_max(n,0);
        vector<int> min_left_right(n,0);

        left_max[0] = height[0];
        for(int i = 1; i < n; i++){
            left_max[i] = max(left_max[i-1], height[i]);
        }

        right_max[n-1] = height[n-1];
        for(int i = n-2; i >=0 ; i--){
            right_max[i] = max(right_max[i+1], height[i]);
        }
        int ans = 0;
        int water_i;
        for(int i = 0; i < n; i++){
            min_left_right[i] = min(left_max[i], right_max[i]);
            water_i = min_left_right[i] - height[i];
            if (water_i <= 0) water_i = 0;
            ans += water_i;
        }

        // for(int i = 0; i < n; i++){
        // }

        return ans;


    }
};