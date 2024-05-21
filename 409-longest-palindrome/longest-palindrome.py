class Solution:
    def longestPalindrome(self, s: str) -> int:
        # Initialize the total length of the longest palindrome
        max_palindrome_length = 0
        
        # Dictionary to count the frequency of each character
        char_count = {}
        
        # Flag to check if there is any character with an odd frequency
        has_odd_frequency = False
        
        # Count the frequency of each character in the string
        for char in s:
            if char in char_count:
                char_count[char] += 1
            else:
                char_count[char] = 1

        # Calculate the maximum length of a palindrome that can be built
        for char, freq in char_count.items():
            if freq % 2 == 0:
                # If the frequency is even, it can fully contribute to the palindrome length
                max_palindrome_length += freq
            else:
                # If the frequency is odd, add the largest even part to the palindrome length
                max_palindrome_length += (freq - 1)
                has_odd_frequency = True
                
        # If there is any character with an odd frequency, we can use one such character in the center of the palindrome
        if has_odd_frequency:
            return max_palindrome_length + 1
        else:
            return max_palindrome_length
