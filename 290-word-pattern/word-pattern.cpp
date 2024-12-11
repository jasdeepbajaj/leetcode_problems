class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string token;
        int countWords = 0;
        
        while (getline(ss, token, ' ')) {
            words.push_back(token);
            countWords++;
        }
         
        int n = pattern.size();
        
        if (countWords != n) {
            cout << "yahan";  // Corrected: placed inside braces
            return false;
        }

        unordered_map<string, char> mapS;
        unordered_map<char, string> mapPattern;

        for (int i = 0; i < n; ++i) {
            char charP = pattern[i];
            string stringS = words[i];

            if (mapS.find(stringS) != mapS.end() && mapS[stringS] != charP) {
                cout << "yahan2";  // Corrected: placed inside braces
                return false;
            }

            if (mapPattern.find(charP) != mapPattern.end() && mapPattern[charP] != stringS) {
                cout << "yahan3";  // Corrected: placed inside braces
                return false;
            }

            mapS[stringS] = charP;
            mapPattern[charP] = stringS;
        }

        cout << "yahan4";  // Corrected: placed inside braces
        return true;
    }
};
