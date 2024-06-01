# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        current1 = list1
        current2 = list2
        head = ListNode(0)
        current = head

        while current1 and current2:
            if current1.val > current2.val:
                newNode = ListNode(current2.val)
                current.next = newNode
                current = current.next
                current2 = current2.next

            else:
                newNode = ListNode(current1.val)
                current.next = newNode
                current = current.next
                current1 = current1.next
            
        while current1:
            newNode = ListNode(current1.val)
            current.next = newNode
            current = current.next
            current1 = current1.next

        while current2:
            newNode = ListNode(current2.val)
            current.next = newNode
            current = current.next
            current2 = current2.next



        return head.next