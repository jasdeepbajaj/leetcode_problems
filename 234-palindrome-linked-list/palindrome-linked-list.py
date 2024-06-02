# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True
        
        stack = []
        current = head
        
        # Step 1: Traverse the list and push values onto the stack
        while current:
            stack.append(current.val)
            current = current.next
        
        current = head
        
        # Step 2: Traverse the list again and compare with stack values
        while current:
            if current.val != stack.pop():
                return False
            current = current.next
        
        return True