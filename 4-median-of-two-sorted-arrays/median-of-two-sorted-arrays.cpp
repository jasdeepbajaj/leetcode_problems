class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int u = 0;
        int v = 0;

        while (u < nums1.size() && v < nums2.size()){
            if(nums1[u] <= nums2[v]){
                nums3.push_back(nums1[u]);
                u++;
            }

            else if (nums2[v] < nums1[u]){
                nums3.push_back(nums2[v]);
                v++;
            }
        }

        while (u < nums1.size()){
            nums3.push_back(nums1[u]);
            u++;
        }

        while (v < nums2.size()){
            nums3.push_back(nums2[v]);
            v++;
        }

        for(int i = 0; i <nums3.size(); i++){
            std::cout<<nums3[i]<<std::endl;
        }

        int n = nums3.size();
        if (n%2 != 0) return nums3[n/2];
        else return (nums3[n/2 - 1] + nums3[n/2])/2.0;
        // return 2.3;

    }
};