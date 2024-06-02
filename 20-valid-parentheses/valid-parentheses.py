class Solution:
    def isValid(self, s: str) -> bool:
        # Dictionary to map opening brackets to their corresponding closing brackets
        bracket_map = {'(': ')', '{': '}', '[': ']'}

        # If the length of the string is odd, it cannot be a valid sequence
        if len(s) % 2 != 0:
            return False

        # Stack to keep track of opening brackets
        stack = []

        # Iterate through each character in the string
        for bracket in s:
            # If the character is an opening bracket, push it onto the stack
            if bracket in bracket_map:
                stack.append(bracket)
            else:
                # If the stack is empty or the top of the stack does not match the closing bracket, return False
                if len(stack) == 0 or bracket_map[stack.pop()] != bracket:
                    return False

        # If the stack is not empty, there are unmatched opening brackets, return False
        if stack:
            return False
        else:
            return True