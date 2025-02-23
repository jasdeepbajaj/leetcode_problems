class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;
        unordered_set<int> st;
        for (auto num : nums) st.insert(num);
        int longest = 1;

        for(auto curr : st){
            int prev = curr - 1;
            if (st.find(prev) == st.end()){ //curr is the starting point of the sequence
                int count = 1;
                int next = curr + 1;
                while (st.find(next) != st.end()){
                    count++;
                    next++;
                }
                longest = max(longest, count);
            }
            else{
                continue;
            }
        }

        return longest;
    }
};