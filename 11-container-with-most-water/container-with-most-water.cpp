class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = INT_MIN;
        
        int curr_area = 0;
        while(left < right){
            curr_area = (right - left) * min(height[left], height[right]);
            maxArea = max(maxArea, curr_area);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return maxArea;
    }
};