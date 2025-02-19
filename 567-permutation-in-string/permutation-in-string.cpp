class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        vector<int> count1(26, 0), count2(26, 0);
        
        // Initialize counts for the first window
        for (int i = 0; i < n1; ++i) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        
        // Check initial window
        if (count1 == count2) return true;

        // Slide the window
        for (int u = n1; u < n2; ++u) {
            int outgoing = s2[u - n1] - 'a'; // Leftmost character exiting
            int incoming = s2[u] - 'a';       // New character entering
            
            count2[outgoing]--;
            count2[incoming]++;
            
            if (count1 == count2) return true;
        }
        
        return false;
    }
};
