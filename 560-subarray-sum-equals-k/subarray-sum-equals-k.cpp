#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix_sum(n, 0);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefix_sum[i] = sum;
        }

        unordered_map<int, int> dict; // prefix_sum, freq

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (prefix_sum[i] == k) count++;
            
            // Corrected the diff calculation
            int diff = prefix_sum[i] - k;

            if (dict.find(diff) != dict.end()) {
                count += dict[diff];
            }
            
            dict[prefix_sum[i]]++;
        }

        return count;
    }
};
