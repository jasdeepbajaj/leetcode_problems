class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> bracket_map = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        if (s.length() % 2 != 0) return false;

        stack<char> st;

        for (char bracket : s) {
            if (bracket_map.find(bracket) != bracket_map.end()) st.push(bracket);
            
            else {
                if (st.empty() || bracket_map[st.top()] != bracket) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};