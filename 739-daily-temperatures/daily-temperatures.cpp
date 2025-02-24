class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st; // Stores (temperature, index)
        
        for (int i = 0; i < n; i++) {
            int curr_temp = temperatures[i];
            while (!st.empty() &&   curr_temp >  st.top().first) {
                auto topPair = st.top();
                st.pop();
                ans[topPair.second] = i - topPair.second;
            }
            st.push({curr_temp, i});
        }
        return ans;
    }
};
