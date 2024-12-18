class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last_index = m + n - 1;

        while(m>0 && n>0){
            if (nums1[m-1] >= nums2[n-1]){
                nums1[last_index] = nums1[m-1];
                last_index--;
                m--;
            }
            else{
                nums1[last_index] = nums2[n-1];
                last_index--;
                n--;
            }
        }

        while (n>0){
            nums1[last_index] = nums2[n-1];
            last_index--;
            n--;
        }


    }
};