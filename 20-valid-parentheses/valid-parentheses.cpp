class Solution {
public:
    bool isValid(string s) {
        // Unordered map to store the matching pairs of brackets
        unordered_map<char, char> bracket_map = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        // If the length of the string is odd, it cannot be a valid sequence
        if (s.length() % 2 != 0) {
            return false;
        }

        // Stack to keep track of opening brackets
        stack<char> stack;

        // Iterate through each character in the string
        for (char bracket : s) {
            // If the character is an opening bracket, push it onto the stack
            if (bracket_map.find(bracket) != bracket_map.end()) {
                stack.push(bracket);
            } else {
                // If the stack is empty or the top of the stack does not match the closing bracket, return False
                if (stack.empty() || bracket_map[stack.top()] != bracket) {
                    return false;
                }
                stack.pop();
            }
        }

        // If the stack is not empty, there are unmatched opening brackets, return False
        if (!stack.empty()) {
            return false;
        } else {
            return true;
        }
    }
};
