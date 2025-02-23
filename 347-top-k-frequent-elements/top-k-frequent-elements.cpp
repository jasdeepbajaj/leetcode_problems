class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Map to count frequency of each number
        unordered_map<int, int> frequencyMap;
        
        // Bucket array where index represents frequency
        vector<vector<int>> buckets(nums.size() + 1);

        // Count the frequency for each number in nums
        for (int num : nums) {
            frequencyMap[num]++;
        }
        
        // Place numbers into corresponding bucket based on frequency count
        for (const auto& pair : frequencyMap) {
            int number = pair.first;
            int freq = pair.second;
            buckets[freq].push_back(number);
        }
        
        vector<int> result;
        // Iterate buckets in reverse (highest frequency first)
        for (int freq = buckets.size() - 1; freq > 0; --freq) {
            // Add each number from the current bucket into result
            for (int number : buckets[freq]) {
                result.push_back(number);
                if (result.size() == k)
                    return result;  // Stop if we have collected k numbers
            }
        }
        return result;
    }
};
