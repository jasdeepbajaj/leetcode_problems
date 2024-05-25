class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int p1 = 0;
        int p2 = 0;

        while(p1<m && p2<n){
            if(nums1[p1] <= nums2[p2]){
                temp.push_back(nums1[p1]);
                p1++;
            }
            else{
                temp.push_back(nums2[p2]);
                p2++;
            }
        }

        while(p1<m){
            temp.push_back(nums1[p1]);
            p1++;
        }

        while(p2<n){
            temp.push_back(nums2[p2]);
            p2++;
        }
        
        for(int i=0; i<m+n; i++){
            nums1[i] = temp[i];
        }

    }
};