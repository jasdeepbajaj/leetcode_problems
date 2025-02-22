class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        if (n1 != n2) return false;

        vector<int> counts(26,0);
        vector<int> countt(26,0);

        for(int i =0; i<n1;i++){
            char chars = s[i];
            char chart = t[i];
            counts[chars - 'a']++;
            countt[chart - 'a']++;
        }

        if (counts == countt) return true;
        return false;
    }
};