# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if head is None:
            return head
            
        stack = []
        current = head

        while current:
            stack.append(current.val)
            current = current.next

        new_head = ListNode(stack.pop())
        temp = new_head
        i = len(stack) - 1

        while i>=0:
            next_el = ListNode(stack[i])
            temp.next = next_el
            temp = temp.next
            i-=1

        return new_head
