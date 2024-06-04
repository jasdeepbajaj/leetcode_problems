class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Initialize a map to store the count of each element
        map<int, int> dict;
        
        // Iterate through the input vector and count occurrences of each element
        for(auto itr : nums) {
            // Increment the count for the element only if it appears less than twice
            if(dict[itr] < 2) dict[itr]++;
        }

        // Clear the original nums vector to prepare for reconstruction
        nums.clear();
        
        // Iterate through the map to reconstruct the vector with at most two duplicates of each element
        for(auto itr : dict) {
            // Add the element to nums as many times as its count in the map
            while(itr.second != 0) {
                nums.push_back(itr.first);
                itr.second--;  // Decrement the count
            }
        }

        // Return the size of the modified nums vector
        return nums.size();
    }
};
