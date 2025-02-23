class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        for(const auto &s : strs){
            vector<int> count(26,0);
            for (char c : s){
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i< 26; i++){
                key += ',';
                key += to_string(count[i]);

            }
            dict[key].push_back(s);
        }
        vector<vector<string>> result;
        // for (auto key : dict){
        //     result.push_back(dict[key]);
        // }
        for (const auto &p : dict) {
            // p is a pair: p.first is the key, p.second is the value
            result.push_back(p.second);
        }

        

        return result;
    }
};